#!/usr/bin/env ruby

# This file is going to be refactored soon, it's just to test objc processing code

require 'rubygems'
require 'enumerator'
require 'treetop'
require 'polyglot'
require 'pp'

class ObjectiveC
  BASIC_TYPES = {
    '@' => 'id',
    '#' => 'class',
    ':' => 'SEL',
    'c' => 'char',
    'C' => 'unsigned char',
    's' => 'short',
    'S' => 'unsigned short',
    'i' => 'int',
    'I' => 'unsigned int',
    'l' => 'long',
    'L' => 'unsigned long',
    'q' => 'long long',
    'Q' => 'unsigned long long',
    'f' => 'float',
    'd' => 'double',
    'b' => 'unsigned',
    'B' => 'bool',
    'v' => 'void',
    '?' => 'undefined',
    '^' => 'pointer',
    '*' => 'char *',
    '%' => 'atom',
    '!' => 'vector'
  }
  
  Treetop.load "objc"
  
  def initialize(content, object)
    @source = content
    @object = object
    
    data = object[:segments]['__DATA']
    
    sections = data[:sections]
    
    classlist_offset = sections['__objc_classlist'][:offset]
    classlist_size = sections['__objc_classlist'][:size]
    
    content.seek(object[:offset] + classlist_offset, IO::SEEK_SET)

    classlist = content.read(classlist_size).unpack("V*")
    
    classlist.each do |class_offset| 
      isa_ptr, superclass_ptr, cache_ptr, vtable_ptr, info_ptr = virtual_read(class_offset, 20).unpack("V*")
      
      unk0, unk1, unk2, unk3, name_ptr, methodlist_ptr, unk4, ivarlist_ptr = virtual_read(info_ptr, 32).unpack("V*")
      
      puts "@interface #{virtual_gets(name_ptr)}\n{"
      
      if ivarlist_ptr != 0
        ivar_size, ivar_count = virtual_read(ivarlist_ptr, 8).unpack("V*")
    
        ivars = virtual_read(ivarlist_ptr + 8, ivar_size * ivar_count)
      
        ivar_count.times do |i|
          ivar_unk0, ivar_name_ptr, ivar_type_ptr, ivar_unk1, ivar_unk2 = ivars[ivar_size * i, ivar_size].unpack("V*")
        
          break if ivar_name_ptr == 0
        
          ivar_name = virtual_gets(ivar_name_ptr)
          ivar_type = virtual_gets(ivar_type_ptr)
                
          puts "\t#{ObjectiveC.merge_typenames(ivar_name, ivar_type)}; // #{ivar_type}"
        end
      end
      puts "}\n\n"
      
      if methodlist_ptr != 0
        method_size, method_count = virtual_read(methodlist_ptr, 8).unpack("V*")
      
        methods = virtual_read(methodlist_ptr + 8, method_size * method_count)
      
        method_count.times do |i|
          method_name_ptr, method_type_ptr, handler_ptr = methods[method_size * i, method_size].unpack("V*")
        
          method_name = virtual_gets(method_name_ptr)
          method_type = virtual_gets(method_type_ptr)
        
          method = method_name #ObjectiveC.decode_selector_parameters(method_name, method_type)
        
          puts "- #{ObjectiveC.merge_typenames(method_name, method_type)}; // #{method_type}"
        end
      end
      
      puts "@end\n\n"
    end
  end
  
  # This needs to be moved to mach-o as a method of image
  def virtual_read(offset, length)
    @object[:segments].each_value do |info|
      if offset >= info[:vm_addr] && offset < info[:vm_addr] + info[:vm_size]
        read_offset = @object[:offset] + info[:file_offset] + (offset - info[:vm_addr])
        
        old_offset = @source.tell
        @source.seek(read_offset, IO::SEEK_SET)
        buffer = @source.read(length)
        
        @source.seek(old_offset, IO::SEEK_SET)
        return buffer
      end
    end
  end
  
  def virtual_gets(offset)
    @object[:segments].each_value do |info|
      if offset >= info[:vm_addr] && offset < info[:vm_addr] + info[:vm_size]
        read_offset = @object[:offset] + info[:file_offset] + (offset - info[:vm_addr])
        
        old_offset = @source.tell
        
        @source.seek(read_offset, IO::SEEK_SET)
        buffer = @source.gets("\x00")[0..-2]
        
        @source.seek(old_offset, IO::SEEK_SET)
        return buffer
      end
    end
  end
  
  def file_read(offset, length)
    
  end
  
  def self.merge_typenames(name, types)
    decoded_types = decode_types(types)
    
    if decoded_types.size == 1
      # we have a member variable
      
      if decoded_types[0] =~ /^unsigned :(\d+)$/
        "unsigned #{name}:#{$1}"
      elsif decoded_types[0] =~ /^(.*)(\[\d+\])$/
        "#{$1} #{name}#{$2}"
      else
        "#{decoded_types[0]} #{name}"
      end
    else
      # we have a selector
      
      # ignore the return value, object receiver and selector
      parameter_types = decoded_types[3..-1]
      
      # split the selector into its parts
      selector_parts = name.split(':')
      
      # interleave the selector parts with their types
      full_name = selector_parts.zip(parameter_types).map{|part| part.compact.size == 1 ? "#{part[0]}" : "#{part[0]}: (#{part[1]})"}.join(' ')
      
      "(#{decoded_types[0]}) #{full_name}"
    end
  end
  
  def self.decode_types(types)    
    parser = ObjectiveCTypeDescriptorParser.new
    
    parsed = parser.parse(types)
        
    types_array = parsed.elements.map do |element|
      type = element.text_value
      
      pointer = if type[0] == ?^
        type = type[1..-1]
        true
      else
        false
      end
      
      if type[0] == ?{
        # TODO: smarter AST usage
        "struct #{element.elements[0].elements[1].elements[1].text_value}"
      elsif type[0] == ?(
        ""
      elsif type[0] == ?[
        count = element.elements[0].elements[1].elements[1].text_value.to_i
        
        "#{BASIC_TYPES[element.elements[0].elements[1].elements[2].text_value]}[#{count}]"
      elsif type[0] == ?b
        "unsigned :#{element.elements[1].text_value.to_i}"
      elsif type[0] == ?@
        # EWW ugly, do smarter AST parsing
        if element.elements && element.elements[0] &&
           element.elements[0].elements && element.elements[0].elements[1] &&
           element.elements[0].elements[1].elements && element.elements[0].elements[1].elements[1] &&
           element.elements[0].elements[1].elements[1].elements && element.elements[0].elements[1].elements[1].elements[1]
          pointer = true
          value = element.elements[0].elements[1].elements[1].elements[1].text_value
          if value[0] == ?<
            "id#{value}"
          else
            value
          end
        else
          BASIC_TYPES['@']
        end
      else
        BASIC_TYPES[type[0, 1]]
      end + (pointer ? " *" : "")
    end
        
    types_array
  end
end
