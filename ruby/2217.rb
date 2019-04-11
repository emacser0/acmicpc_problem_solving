l=[];gets.to_i.times{l<<gets.to_i};l.sort!;m=0;l.length.times{|i|s=(l.length-i)*l[i];m=[m,s].max};puts m
