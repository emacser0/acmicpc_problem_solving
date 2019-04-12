$n=gets.to_i
l=[]
$n.times{l<< gets.split.map(&:to_i)}
def left(l)
  $n.times{|i|
    stk=[-1];f=0
    0.upto($n-1){|j|
      if stk[stk.length-1]==l[i][j] and f==0
        stk[stk.length-1]*=2;f=1
      elsif l[i][j]!=0
        stk << l[i][j];f=0
      end
    }
    stk.shift
    (stk << 0)while stk.length<$n
    $n.times{|j|l[i][j]=stk[j]}
  }
end
def right(l)
  $n.times{|i|
    stk=[-1];f=0
    ($n-1).downto(0){|j|
      if stk[stk.length-1]==l[i][j] and f==0
        stk[stk.length-1]*=2;f=1
      elsif l[i][j]!=0
        stk << l[i][j];f=0
      end
    }
    stk.shift
    (stk << 0)while stk.length<$n
    $n.times{|j|l[i][j]=stk[$n-j-1]}
  }
end
def up(l)
  $n.times{|i|
    stk=[-1];f=0
    0.upto($n-1){|j|
      if stk[stk.length-1]==l[j][i] and f==0
        stk[stk.length-1]*=2;f=1
      elsif l[j][i]!=0
        stk << l[j][i];f=0
      end
    }
    stk.shift
    (stk << 0)while stk.length<$n
    $n.times{|j|l[j][i]=stk[j]}
  }
end
def down(l)
  $n.times{|i|
    stk=[-1];f=0
    ($n-1).downto(0){|j|
      if stk[stk.length-1]==l[j][i] and f==0
        stk[stk.length-1]*=2;f=1
      elsif l[j][i]!=0
        stk << l[j][i];f=0
      end
    }
    stk.shift
    (stk << 0)while stk.length<$n
    $n.times{|j|l[j][i]=stk[$n-j-1]}
  }
end
$m=0
def dfs(x,l)
  ($m=[$m,l.map{|x|x.max}.max].max;return) if x==5
  nl=[];l.each {|x|nl<< x.dup}
  up(nl);dfs(x+1,nl)
  nl=[];l.each {|x|nl<< x.dup}
  down(nl);dfs(x+1,nl)
  nl=[];l.each {|x|nl<< x.dup}
  right(nl);dfs(x+1,nl)
  nl=[];l.each {|x|nl<< x.dup}
  left(nl);dfs(x+1,nl)
end
dfs(0,l)
p $m
