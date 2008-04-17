class MachO
  HOST_BYTE_ORDER = ("\x01\x02\x03\x04".unpack("N")[0] == 0x01020304) ? :little : :big
  NOT_HOST_BYTE_ORDER = ([:big, :little] - [HOST_BYTE_ORDER])[0]
  
  CPU_TYPES = {
    1 => :vax, 
    6 => :mc680x0, 
    7 => :x86, 
    (7 | 0x01000000) => :x86_64, 
    8 => :mips, 
    10 => :mc98000, 
    11 => :hppa, 
    12 => :arm, 
    13 => :mc88000, 
    14 => :sparc, 
    15 => :i860, 
    16 => :alpha, 
    18 => :powerpc, 
    (18 | 0x01000000) => :powerpc64
  }
  
  CPU_SUBTYPES = {
    :vax => {
      0   => :all,
      1   => :vax780,
      2   => :vax785,
      3   => :vax750,
      4   => :vax730,
      5   => :uvaxI,	 
      6   => :uvaxII,
      6   => :vax8200,
      7   => :vax8500,
      8   => :vax8600,
      9   => :vax8650,
      10  => :vax8800,
      11  => :uvaxIII
    },

    :mc680x0 => {
      1   => :all, # also :mc68030
      2   => :mc86040,
      3   => :mc86030_only
    },


    :x86 => {

    },

    :mips => {
      0   => :all,
      1   => :r2300,
      2   => :r2600,
      3   => :r2800,
      4   => :r2000a,
      5   => :r2000,
      6   => :r3000a,
      7   => :r3000    
    },

    :mc98000 => {
      0   => :all,
      1   => :mc98601
    },

    :hppa => {
      0   => :all, # also :7100
      1   => '7100lc'.to_sym
    },

    :mc88000 => {
      0   => :all,
      1   => :mc88100,
      2   => :mc88110
    },

    :sparc => {
      0   => :all
    },

    :i860 => {
      0   => :all,
      1   => '860'.to_sym
    },

    :powerpc => {
      0   => :all,
      1   => '601'.to_sym,	
      2   => '602'.to_sym,	
      3   => '603'.to_sym,	
      4   => '603e'.to_sym,
      5   => '603ev'.to_sym,
      6   => '604'.to_sym,	
      7   => '604e'.to_sym,
      8   => '620'.to_sym,	
      9   => '750'.to_sym,	
      10  => '7400'.to_sym,
      11  => '7450'.to_sym,
      100 => '970'.to_sym
    },

    :arm => {
      0   => :all,
      5   => :v4t,
      6   => :v6,
      7   => :v5tej,
      8   => :xscale
    }
  }
  
  FILE_TYPES = {
    1   => :object,
    2   => :executable,
    3   => :fvmlib,
    4   => :core,
    5   => :preload,
    6   => :dylib,
    7   => :dylinker,
    8   => :bundle,
    9   => :dylib_stub,
    10  => :dsym
  }
  
  LOAD_COMMANDS = {
    1   => :segment,
    2   => :symtab,
    3   => :symseg,
    4   => :thread,
    5   => :unixthread,
    6   => :loadfvmlib,
    7   => :idfvmlib,
    8   => :ident,
    9   => :fvmfile,
    10  => :prepage,
    11  => :dysymtab,
    12  => :load_dylib,
    13  => :id_dylib,
    14  => :load_dylinker,
    15  => :id_dylinker,
    16  => :prebound_dylib,
    17  => :routines,
    18  => :sub_framework,
    19  => :sub_umbrella,
    20  => :sub_client,
    21  => :sub_library,
    22  => :twolevel_hints,
    23  => :prebind_checksum,
    (24 | 0x80000000) => :load_weak_dylib,
    25  => :segment_64,
    26  => :routines_64,
    27  => :uuid,
    (28 | 0x80000000) => :rpath,
    29  => :code_signature,
    30  => :segment_split_info,
    (31 | 0x80000000) => :reexport_dylib
  }
  
  SYMBOL_TYPES = {
    0   => :undefined,
    2   => :absolute,
    14  => :section,
    12  => :prebound,
    10  => :indirect
  }
  
  attr_reader :architectures
  
  def initialize(content)
    file_magic = content.read(4).unpack("N")[0]
    
    @source = content
    @architectures = {}
    
    # Check to see if we have a fat binary
    if file_magic == 0xcafebabe || file_magic == 0xbebafeca
      # We have a fat binary, next int is the number of architectures
      arch_count = content.read(4).unpack("N")[0]
      
      # Followed by arch_count contiguous architecture descriptors
      arch_count.times do 
        cpu_type, cpu_subtype, offset, size, align = content.read(20).unpack("N*")
        
        cpu_type = CPU_TYPES[cpu_type]
        cpu_subtype = CPU_SUBTYPES[cpu_type][cpu_subtype]
        align = 2 ** align # unused
        
        old_offset = content.tell
        
        # Find out the byte ordering on this arch
        content.seek(offset, IO::SEEK_SET)
        arch_magic = content.read(4).unpack("V")[0]
        
        big_header = (arch_magic == 0xfeedfacf || arch_magic == 0xcffaedfe)
        byte_order = (arch_magic == 0xfeedface || arch_magic == 0xfeedfacf) ? HOST_BYTE_ORDER : NOT_HOST_BYTE_ORDER
        
        # Go back to where we were
        content.seek(old_offset, IO::SEEK_SET)
        
        @architectures[[cpu_type, cpu_subtype]] = {:offset => offset, :size => size, :byte_order => byte_order, :big_header => big_header}
      end
    elsif file_magic = 0xfeedface || file_magic == 0xcefadefe || file_magic == 0xfeedfacf || file_magic == 0xcffaedfe
      # We have a normal binary, check the size of its header
      big_header = (file_magic == 0xfeedfacf || file_magic == 0xcffaedfe)
      byte_order = (file_magic == 0xfeedface || file_magic == 0xfeedfacf) ? HOST_BYTE_ORDER : NOT_HOST_BYTE_ORDER
      
      cpu_type, cpu_subtype = content.read(8).unpack("#{byte_order == :big ? 'N' : 'V'}*")
      
      cpu_type = CPU_TYPES[cpu_type]
      cpu_subtype = CPU_SUBTYPES[cpu_type][cpu_subtype]

      @architectures[[cpu_type, cpu_subtype]] = {:offset => 0, :size => content.stat.size, :byte_order => byte_order, :big_header => big_header}
    else
      raise "Not a Mach-O binary"
    end
    
    @architectures.each do |architecture, info|
      # p architecture
      content.seek(info[:offset], IO::SEEK_SET)

      short_format = info[:byte_order] == :big ? "n" : "v"
      int_format = info[:byte_order] == :big ? "N" : "V"
      
      # Ruby doesn't provide endianness control for 64-bit ints, so we'll need to swap them later if necessary
      pointer_format = info[:big_header] ? "Q" : int_format
      
      header_size = info[:big_header] ? 32 : 28
      
      file_type, command_count, commands_size, macho_flags = content.read(header_size).unpack("x12#{int_format}*")
      
      info[:segments] = {}
      info[:sections] = []
      
      info[:symbols] = {}
      
      info[:libraries] = []
      
      command_count.times do 
        command_header = content.read(8)
        command_type, command_size = command_header.unpack("#{int_format}*")
        
        command = command_header + content.read(command_size - 8)
                
        # p LOAD_COMMANDS[command_type]
        case LOAD_COMMANDS[command_type]
        when :uuid
          uuid = command[8, 16].unpack("C*")
        when :load_dylib, :load_weak_dylib, :id_dylib
          name_offset, timestamp, current_version, compatibility_version = command[8, 16].unpack("#{int_format}*")
          info[:libraries] << command[name_offset..-1].unpack("A*")[0]
        when :segment, :segment_64
          segment_name, vm_addr, vm_size, file_offset, file_size, max_prot, init_prot, section_count, segment_flags = command[8, 48].unpack("A16#{pointer_format * 4}#{int_format}*")
                    
          # Swap our pointers if necessary
          if info[:byte_order] != HOST_BYTE_ORDER && info[:big_header]
            vm_addr     = [vm_addr].pack("Q").unpack("C*").inject([0, 56]){|accum, x| p accum; [accum[0] + x * (2 ** accum[1]), accum[1] - 8]}[0]
            vm_size     = [vm_size].pack("Q").unpack("C*").inject([0, 56]){|accum, x| p accum; [accum[0] + x * (2 ** accum[1]), accum[1] - 8]}[0]
            file_offset = [file_offset].pack("Q").unpack("C*").inject([0, 56]){|accum, x| p accum; [accum[0] + x * (2 ** accum[1]), accum[1] - 8]}[0]
            file_size   = [file_size].pack("Q").unpack("C*").inject([0, 56]){|accum, x| p accum; [accum[0] + x * (2 ** accum[1]), accum[1] - 8]}[0]
          end
          
          info[:segments][segment_name] = segment = {:vm_addr => vm_addr, :vm_size => vm_size, :file_offset => file_offset, :file_size => file_size, :max_prot => max_prot, :init_prot => init_prot, :flags => segment_flags}
          
          section_size = info[:big_header] ? 76 : 68
          
          segment[:sections] = {}
          
          section_count.times do |i|
            section_body = command[56 + section_size * i, section_size]
            
            section_name, section_segment_name, addr, size, offset, align, relocation_offset, relocation_count, section_flags = section_body.unpack("A16A16#{pointer_format * 4}#{int_format}*")
            
            # Fix our pointer info
            if info[:byte_order] != HOST_BYTE_ORDER && info[:big_header]
              addr = [addr].pack("Q").unpack("C*").inject([0, 56]){|accum, x| p accum; [accum[0] + x * (2 ** accum[1]), accum[1] - 8]}[0]
              size = [size].pack("Q").unpack("C*").inject([0, 56]){|accum, x| p accum; [accum[0] + x * (2 ** accum[1]), accum[1] - 8]}[0]
            end
      
            segment[:sections][section_name] = section = {:addr => addr, :size => size, :offset => offset, :align => align, :relocation_offset => relocation_offset, :relocation_count => relocation_count, :flags => section_flags}
            
            # Maintain an ordered list of the sections
            info[:sections] << section
          end
        when :code_signature
          data_offset, data_size = command[8, 8].unpack("#{int_format}*")
          
          old_offset = content.tell
          content.seek(info[:offset] + data_offset, IO::SEEK_SET)
          
          #info[:signature_data] = content.read(data_size)
          
          content.seek(old_offset, IO::SEEK_SET)
        when :symtab, :symtab_64
          symbols_offset, symbol_count, strings_offset, strings_size = command[8, 32].unpack("#{int_format}*")
          
          old_offset = content.tell
          
          symbol_size = info[:big_header] ? 16 : 12
          
          symbol_count.times do |i|
            content.seek(info[:offset] + symbols_offset + symbol_size * i, IO::SEEK_SET)
            
            un, type, section, desc, value = content.read(symbol_size).unpack("#{int_format}C2#{short_format}#{pointer_format}")
            
            if info[:byte_order] != HOST_BYTE_ORDER && info[:big_header]
              value = [value].pack("Q").unpack("C*").inject([0, 56]){|accum, x| p accum; [accum[0] + x * (2 ** accum[1]), accum[1] - 8]}[0]
            end
            
            symbol_type = type & 0x0e
            external = (type & 1) != 0
          
            content.seek(info[:offset] + strings_offset + un)
            
            symbol = content.gets("\x00")[0..-2]
            
            info[:symbols][symbol] = {:section => section, :desc => desc, :value => value, :external => external}
            
            if symbol_type == 0
              info[:symbols][symbol][:lazy] = (desc & 1) != 0
            else
              if (info[:symbols][symbol][:defined] = (desc & 2) != 0)
                info[:symbols][symbol][:private] = (desc & 1) != 0
              end
            end
            
            if (desc & 4) != 0
              info[:symbols][symbol][:defined] = false
              info[:symbols][symbol][:lazy] = false
            end
            
            if (desc & 0x10) != 0
              info[:symbols][symbol][:referenced_dynamically] = true
            end
            
            if (desc & 0x40) != 0
              info[:symbols][symbol][:weak_reference] = true
            end
            
            if (desc & 0x80) != 0
              info[:symbols][symbol][:weak_definition] = true
            end
            
            # Check if MH_TWOLEVEL is set
            if (macho_flags & 0x80) != 0
              library_index = ((desc & 0xFF00) >> 8) - 1
              
              if library_index != -1
                info[:symbols][symbol][:library_index] = library_index
              end
            end
          end
          
          content.seek(old_offset, IO::SEEK_SET)
          
        when :dysymtab
          first_local_symbol_index,
          local_symbol_count,
          first_external_symbol_index,
          external_symbol_count,
          first_undefined_symbol_index,
          undefined_symbol_count,
          toc_offset,
          toc_count,
          module_table_offset,
          module_table_count,
          external_table_offset,
          external_table_count,
          indirect_table_offset,
          indirect_table_count,
          external_relocation_table_offset,
          external_relocation_table_count,
          local_relocation_table_offset,
          local_relocation_table_count = command[8, 88].unpack("#{int_format}*")
        end
      end
    end
  end
  
end