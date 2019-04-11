# This Code is very slow but can solve with C/C++/Java/Rust...
# $n=gets.to_i
# $l=$n.times.map{|i|0}
# $c=0
# def queen(x)
#   ($c+=1;return) if x==$n
#   $n.times{|i|
#     f=0
#     $l[x]=i
#     x.times{|j|
#       (f=1;break) if $l[x]==$l[j] or (x-j).abs==($l[x]-$l[j]).abs
#     }
#     queen(x+1) if f==0
#   }
# end
# $n.times{|i|$l[0]=i;queen(1)}
# puts $c
p [0,1,0,0,2,10,4,40,92,352,724,2680,14200,73712,365596][gets.to_i]
