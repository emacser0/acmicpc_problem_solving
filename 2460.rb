p,m=0,0;10.times{a,b=gets.split.map(&:to_i);p+=b-a;m=[p,m].max}
puts m
