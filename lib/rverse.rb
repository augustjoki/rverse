#! /usr/bin/env ruby
require 'objc'
require 'mach-o'
require 'pp'

orig_stdout = $stdout

if ARGV.length > 0
  file = ARGV[0]
  if ARGV.length == 2
    $stdout = File.new(ARGV[1], 'w')
  end
else
  file = "/Volumes/Vail5A225c.CarrierBundle/Applications/MobilePhone.app/MobilePhone"
  #file = "/Users/pumpkin/ObjC2Showcase/build/Debug-iphoneos/ObjC2Showcase.app/ObjC2Showcase"
  file = "/Users/pumpkin/Downloads/UIKit"
end

f = File.open(file)

macho = MachO.new(f)

macho = macho.images[[:arm, :v6]]

#pp macho.symbols

objc = ObjectiveC.new(macho)

f.close

$stdout = orig_stdout
