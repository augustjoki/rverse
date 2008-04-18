#! /usr/bin/env ruby
require 'objc'
require 'mach-o'
if ARGV.length
  file = ARGV[0]
else
  file = "/Volumes/Vail5A225c.CarrierBundle/Applications/MobilePhone.app/MobilePhone"
end

f = File.open(file)

macho = MachO.new(f).architectures[[:arm, :v6]]

objc = ObjectiveC.new(f, macho)

f.close