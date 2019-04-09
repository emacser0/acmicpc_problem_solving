x=gets.to_i/5;puts x+x/5+x/25
#(150..500).each{|x|s=(1..x).inject(:*);t,c=s,0;(t/=10;c+=1)while t%10==0;puts "count(#{x}) = #{c}"}
#
