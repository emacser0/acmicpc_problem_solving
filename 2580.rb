$m=[]
9.times{$m+=[gets.split.map(&:to_i)]}
$seq=[]
$e=0
9.times{|i|9.times{|j|$seq<<[i,j] if $m[j][i]==0}}
def dfs(x)
  return if $e==1
  (9.times{|i|puts $m[i].join(" ")};$e=1;return) if x==$seq.length and $e==0
  c=10.times.map{0}
  9.times{|i|c[$m[i][$seq[x][0]]]+=1;c[$m[$seq[x][1]][i]]+=1}
  a,b=($seq[x][0]/3)*3,($seq[x][1]/3)*3
  3.times{|i|3.times{|j|c[$m[b+j][a+i]]+=1}}
  (1..9).each{|i|($m[$seq[x][1]][$seq[x][0]]=i;dfs(x+1);$m[$seq[x][1]][$seq[x][0]]=0) if c[i]==0 and $e==0}
end
dfs(0)
# Ruby is very slow so it exceeds time limit but pypy3 can get "Accepted"
