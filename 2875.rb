n,m,k=gets.split.map(&:to_i)
(n/2>=m && k>1)?(n-=2;k-=2):(m-=1;k-=1)while k>0
puts [n/2,m].min
puts [n/2,m,(n+m-k)/3]
