( n=$_.to_i
  break if n==0
  s=gets.chomp.chars;l=s.length/n;r=""
  l.times{|i|s[n*i..n*(i+1)-1]=s[n*i..n*(i+1)-1].reverse if i%2==1}
  n.times{|i|l.times{|j|r+=s[i+j*n]}}
  puts r
)while gets
