$n=gets.to_i
l=[]
$n.times{l<< gets.split.map(&:to_i)}
def left(l)
  $n.times{|i|
    stk=[]
    0.upto($n-1){|j|
      if stk.length!=0 and stk[stk.length-1]==l[i][j]
        stk[stk.length-1]*=2
      elsif l[i][j]!=0
        stk << l[i][j]
      end
    }
    (stk << 0)while stk.length<$n
    $n.times{|j|l[i][j]=stk[j]}
  }
end
def right(l)
  $n.times{|i|
    stk=[]
    ($n-1).downto(0){|j|
      if stk.length!=0 and stk[stk.length-1]==l[i][j]
        stk[stk.length-1]*=2
      elsif l[i][j]!=0
        stk << l[i][j]
      end
    }
    (stk << 0)while stk.length<$n
    $n.times{|j|l[i][j]=stk[$n-j-1]}
  }
end
def up(l)
  $n.times{|i|
    stk=[]
    0.upto($n-1){|j|
      if stk.length!=0 and stk[stk.length-1]==l[j][i]
        stk[stk.length-1]*=2
      elsif l[j][i]!=0
        stk << l[j][i]
      end
    }
    (stk << 0)while stk.length<$n
    $n.times{|j|l[j][i]=stk[j]}
  }
end
def down(l)
  $n.times{|i|
    stk=[]
    ($n-1).downto(0){|j|
      if stk.length!=0 and stk[stk.length-1]==l[j][i]
        stk[stk.length-1]*=2
      elsif l[j][i]!=0
        stk << l[j][i]
      end
    }
    (stk << 0)while stk.length<$n
    $n.times{|j|l[j][i]=stk[$n-j-1]
    }
  }
end
$m=0
def bf(x,l)
  if x==5
    $n.times{|i|$m=[$m,l[i].max].max}
    return
  end
  nl=l.dup
  up(nl);bf(x+1,nl)
  nl=l.dup
  down(nl);bf(x+1,nl)
  nl=l.dup
  right(nl);bf(x+1,nl)
  nl=l.dup
  left(nl);bf(x+1,nl)
end
#bf(0,l)
(
  case $_.chomp
  when "u"
    up l
  when "d"
    down l
  when "r"
    right l
  when "l"
    left l
  end
  l.each{|i|
    i.each{|i|
      print "%d " % i
    }
    puts ""
  }
)while gets
p $m
