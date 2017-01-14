#!/usr/bin/env ruby
require 'faker'

n = 2000
l = 2000
q = 1000

def code
  Faker::Lorem.characters(80)
end

def rnd
  [*(1..2000)].sample
end

puts n
puts l

l.times do
  puts code
end

(n / 2).times do |i|
  puts "+#{rnd}"
  puts code
  puts "-#{rnd}"
end

puts q

q.times do
  puts "#{rnd - 1}"
end
