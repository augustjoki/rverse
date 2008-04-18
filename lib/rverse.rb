#! /usr/bin/env ruby
require 'objc'
require 'mach-o'
if ARGV.length > 0
  file = ARGV[0]
else
  file = "/Volumes/Vail5A225c.CarrierBundle/Applications/MobilePhone.app/MobilePhone"
  #file = "/Users/pumpkin/ObjC2Showcase/build/Debug-iphoneos/ObjC2Showcase.app/ObjC2Showcase"
end

f = File.open(file)

macho = MachO.new(f)


macho = macho.images[[:arm, :v6]]

objc = ObjectiveC.new(macho)

f.close