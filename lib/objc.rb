require 'mach-o'
require 'enumerator'
require 'pp'

file = "/Volumes/Vail5A225c.CarrierBundle/Applications/MobilePhone.app/MobilePhone"

f = File.open(file)

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
    'b' => 'bitfield',
    'B' => 'bool',
    'v' => 'void',
    '?' => 'undefined',
    '^' => 'pointer',
    '*' => 'char pointer',
    '%' => 'atom',
    '[' => 'array_start',
    ']' => 'array_end',
    '(' => 'union_start',
    ')' => 'union_end',
    '{' => 'struct_start',
    '}' => 'struct_end',
    '!' => 'vector',
    'r' => 'const'
  }
  
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
        
          puts "\t#{ObjectiveC.decode_type(ivar_type)} #{ivar_name};"
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
        
          method = ObjectiveC.decode_selector_parameters(method_name, method_type)
        
          puts "- #{method}; // #{method_type}"
        end
      end
      
      puts "@end\n\n"
    end
  end
  
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
  
  def self.decode_type(type)
    case type 
    when /^(struct .+)$/
      $1
    when /^([@#:cCsSiIlLqQfdbBv?\^*%\[\]()!r])/
      BASIC_TYPES[$1]
    end
  end
  
  def self.decode_selector_parameters(selector, parameters)
    selector_parts = selector.split(':')
    
    types = parameters.scan(/[@#:cCsSiIlLqQfdbBv?\^*%\[\]()!r]\d+|[\{\}]|[A-Za-z0-9]+|=/)
    
    real_types = []
    
    i = 0
    while i < types.size
      if types[i] != '{'
        real_types << types[i]
      else
        depth = 0
        
        type = nil
        begin
          if types[i] == '{'
            depth += 1
          elsif types[i] == '}'
            depth -= 1
          else
            if depth == 1 && !type
              type = types[i]
            end
          end
          i += 1
        end while depth != 0
        
        real_types << "struct #{type}"
      end
      i += 1
    end
    
    
    return_type = ObjectiveC.decode_type(real_types[0])
    
    method_name = selector_parts.zip(real_types[3..-1].map{|type| "(#{ObjectiveC.decode_type(type)})"}).map{|part| part.compact.join(":")}.join(" ")
    
    "(#{return_type}) #{method_name}"
  end
end

macho = MachO.new(f).architectures[[:arm, :v6]]

objc = ObjectiveC.new(f, macho)

f.close