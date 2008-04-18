#! /usr/bin/env ruby
require 'objc'
require 'mach-o'

orig_stdout = $stdout

if ARGV.length
  file = ARGV[0]
  if ARGV.length == 2
    $stdout = File.new(ARGV[1], 'w')
  end
else
  file = "/Volumes/Vail5A225c.CarrierBundle/Applications/MobilePhone.app/MobilePhone"
end

f = File.open(file)

macho = MachO.new(f).architectures[[:arm, :v6]]

objc = ObjectiveC.new(f, macho)

f.close

$stdout = orig_stdout