$l=[]
45.downto(0){|i|$l << i*(i+1)/2;}
def dfs(n,l,c,x)
  return if $r==1
  if c==3
    $r=1 if l[0]>0 and l[1]>0 and l[2]>0 and l.sum==$n
    return
  end
  (x+=1)while $l[x]>n
  x+1.upto(45) {|i|
    (nl=l.dup;nl << $l[i];dfs(n-$l[i],nl,c+1,x)) if n-$l[i]>=0
  }
end
gets.to_i.times{|i|
  $r=0
  $n=gets.to_i
  dfs($n,[],0,0)
  p $r
}
