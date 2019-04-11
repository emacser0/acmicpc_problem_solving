(a=gets.chomp.downcase.chars
break if a[0]=='#'
puts a[0]+" %d"%(a.select{|i|i==a[0]}.length-1)
)while 1
