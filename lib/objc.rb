#!/usr/bin/env ruby

# This file is going to be refactored soon, it's just to test objc processing code
# It should eventually output its information to an abstract format, that can then be
# output to objc syntax if necessary

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
    '!' => 'vector',
    'r' => 'const'
  }
  
  PROPERTY_MODIFIERS = {
    'C' => 'copy',
    'R' => 'readonly',
    '&' => 'retain'
  }
  
  Treetop.load "grammars/objc_typedescriptor"
  
  def initialize(object)
    data = object.segments['__DATA']
    
    sections = data[:sections]
    
    classlist_offset = sections['__objc_classlist'][:offset]
    classlist_size = sections['__objc_classlist'][:size]
    
    @object = object
    @source = object.physical
    
    content = object.physical
    content.seek(classlist_offset, IO::SEEK_SET)

    classlist = content.read(classlist_size).unpack("V*")
    
    virtual = object.virtual
    
    classlist.each do |class_offset| 
      virtual.seek(class_offset)
      metaclass_ptr, superclass_ptr, cache_ptr, vtable_ptr, info_ptr = virtual.read(20).unpack("V*")
      
=begin      
      superclass_name = if object.relocations[class_offset + 4] =~ /^_OBJC_CLASS_\$_(.*)$/
        $1
      else
        virtual.seek(superclass_ptr + 16)
        virtual.seek(virtual.read(4).unpack("V*")[0] + 16)
        superclass_name_ptr = virtual.read(4).unpack("V*")[0]

        virtual.seek(superclass_name_ptr)
        virtual.gets("\x00").chop
      end
=end
      superclass_name = "NSPumpkin"
            
      virtual.seek(info_ptr)
      unk0, unk1, unk2, unk3, name_ptr, methodlist_ptr, unk4, ivarlist_ptr, unk5, propertylist_ptr = virtual.read(40).unpack("V*")
      
      virtual.seek(name_ptr)
      puts "@interface #{virtual.gets("\x00").chop} : #{superclass_name}\n{"
      
      if ivarlist_ptr != 0
        virtual.seek(ivarlist_ptr)
        ivar_size, ivar_count = virtual.read(8).unpack("V*")
    
        # Maybe I should avoid reading it all into memory...
        ivars = virtual.read(ivar_size * ivar_count)
      
        ivar_count.times do |i|
          ivar_unk0, ivar_name_ptr, ivar_type_ptr, ivar_unk1, ivar_memsize = ivars[ivar_size * i, ivar_size].unpack("V*")
        
          break if ivar_name_ptr == 0

          virtual.seek(ivar_name_ptr)
          ivar_name = virtual.gets("\x00").chop
          
          virtual.seek(ivar_type_ptr)
          ivar_type = virtual.gets("\x00").chop
          
          begin
            puts "\t#{ObjectiveC.merge_typenames(ivar_name, ivar_type)}; // #{ivar_type}"
          rescue
            puts "// TO BE FIXED (unrecognized member variable)"
          end
        end
      end
      puts "}\n\n"
      
      if metaclass_ptr != 0
        virtual.seek(metaclass_ptr + 16)
        metaclass_info = virtual.read(4).unpack("V*")[0]
        
        virtual.seek(metaclass_info + 20)
        class_methodlist_ptr = virtual.read(4).unpack("V*")[0]
        
        if class_methodlist_ptr != 0
          virtual.seek(class_methodlist_ptr)
          method_size, method_count = virtual.read(8).unpack("V*")

          methods = virtual.read(method_size * method_count)
      
          method_count.times do |i|
            method_name_ptr, method_type_ptr, handler_ptr = methods[method_size * i, method_size].unpack("V*")
        
            virtual.seek(method_name_ptr)
            method_name = virtual.gets("\x00").chop
          
            virtual.seek(method_type_ptr)
            method_type = virtual.gets("\x00").chop
            
            begin
              puts "+ #{ObjectiveC.merge_typenames(method_name, method_type)}; // #{method_type}"
            rescue
              puts "// TO BE FIXED (unrecognized class method)"
            end
          end
          puts
        end
      end
      
      if methodlist_ptr != 0
        virtual.seek(methodlist_ptr)
        method_size, method_count = virtual.read(8).unpack("V*")
      
        methods = virtual.read(method_size * method_count)
      
        method_count.times do |i|
          method_name_ptr, method_type_ptr, handler_ptr = methods[method_size * i, method_size].unpack("V*")
        
          virtual.seek(method_name_ptr)
          method_name = virtual.gets("\x00").chop
          
          virtual.seek(method_type_ptr)
          method_type = virtual.gets("\x00").chop
      
          begin
            puts "- #{ObjectiveC.merge_typenames(method_name, method_type)}; // #{method_type}"
          rescue
            puts "// TO BE FIXED (unrecognized instance method)"
          end
        end
      end
      
      puts
      if propertylist_ptr != 0
        virtual.seek(propertylist_ptr)
        property_size, property_count = virtual.read(8).unpack("V*")
        
        properties = virtual.read(property_size * property_count)
        
        property_count.times do |i|
          property_name_ptr, property_type_ptr = properties[property_size * i, property_size].unpack("V*")
          
          virtual.seek(property_name_ptr)
          property_name = virtual.gets("\x00").chop
          
          virtual.seek(property_type_ptr)
          property_type = virtual.gets("\x00").chop
          
          property_info = property_type.split(',')
          
          if property_info.size > 2
            modifiers = "(#{PROPERTY_MODIFIERS[property_info[1]]})"
          else
            modifiers = ""
          end
          
          puts "@property#{modifiers} #{ObjectiveC.merge_typenames(property_name, property_info[0][1..-1])};"
        end
        puts
      end
      
      puts "@end\n\n"
    end
  end
  
  def self.merge_typenames(name, types)
    
    decoded_types = decode_types(types)
    
    if decoded_types.size == 1
      # we have a member variable
      
      # Some types (bitfields and arrays) need swappage
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
      
      if type[0] == ?V
        type = type[1..-1]
      end
      
      const = if type[0] == ?r
        type = type[1..-1]
        true
      else
        false
      end
      
      pointer = if type[0] == ?^
        type = type[1..-1]
        true
      else
        false
      end
      
      (const ? "const " : "") + if type[0] == ?{
        # TODO: smarter AST usage
        "struct #{element.elements[0].elements[1].elements[1].text_value}"
      elsif type[0] == ?(
        # TODO: this all should be outputting its info to an abstract structure, rather than as a string to stdout
        union_name = element.elements[0].elements[1].elements[1].text_value
        
        begin
          union_members = []
          element.elements[0].elements[1].elements[3].elements.each do |el|
            union_element_name = el.elements[0].text_value.gsub(/\"/, '')
            union_element_type = el.elements[1].text_value
          
            if union_element_type[0] == ?^
              union_members << "#{BASIC_TYPES[union_element_type[1, 1]]} * #{union_element_name}"
            else
              union_members << "#{BASIC_TYPES[union_element_type[0, 1]]} #{union_element_name}"
            end
          end
        
          "union #{union_name} {\n" +
          union_members.map{|member| "\t\t#{member};"}.join("\n") + "\n\t}"
        rescue
          "union #{union_name}"
        end
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
