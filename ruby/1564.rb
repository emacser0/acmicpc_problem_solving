r=1;(1..gets.to_i).each {|x|r=r*x;(r/=10)while r%10==0;r%=10000000000}
puts r.to_s.reverse[0..4].reverse
