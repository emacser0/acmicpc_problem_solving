n,r,l=gets.to_i,[],gets.split.map(&:to_i);n.times{|i|r.insert(i-l[i],i+1)};puts r.join(' ')
