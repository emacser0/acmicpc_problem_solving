a,b,c,d=gets.split.map(&:to_i)
a.times{puts (gets.chomp.chars.map{|i|i*d}.join("")+"\n")*c}
