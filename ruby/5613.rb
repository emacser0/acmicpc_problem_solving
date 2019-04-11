s,b=0,'+'
(a=gets.to_i
s=b=='+'?s+a:(b=='-'?s-a:(b=='*'?s*a:(b=='/'?s/a:s)))
b=gets[0]
break if b=='=')while 1
puts s
