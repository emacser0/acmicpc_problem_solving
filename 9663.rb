$n=gets.to_i
$l=(0..$n-1).map{|i|[0]*$n}
$m=0
def queen(x,y,c)
  nx,ny=-1,-1
  (x..$n-1).each{|i|(y..$n-1).each{|j|nx,ny=i,j if $l[j][i]==0}}
  ($m=[$m,c].max;return) if nx==ny==-1
  queen nx,ny,c
  (x..$n-1).each{|i|$l[y][i]+=1}
  (y..$n-1).each{|i|$l[i][x]+=1}
  (0..$n-[x,y].max-1).each{|i|puts "i=#{i}";$l[y+i][x+i]+=1}
  $l.each{|i|p i}
  queen x+1,y,c if x+1<n
  queen x,y+1,c if y+1<n
  (x..$n-1).each{|i|$l[y][i]-=1}
  (y..$n-1).each{|i|$l[i][x]-=1}
  (0..$n-[x,y].max-1).each{|i|$l[y+i][x+i]-=1}
end

queen(0,0,0)
