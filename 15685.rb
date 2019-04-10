l,r,dx,dy=(0..101).map{[0]*101},0,[1,0,-1,0],[0,-1,0,1]
gets.to_i.times{x,y,d,g=gets.split.map(&:to_i)
c=[[x,y],[x+dx[d],y+dy[d]]]
l[y][x]=l[y+dy[d]][x+dx[d]]=1
(s=c.length
(s-2).downto(0){|i|n=c[i].dup;
n[0],n[1]=c[s-1][0]-(n[1]-c[s-1][1]),c[s-1][1]+(n[0]-c[s-1][0])
l[n[1]][n[0]]=1;c<<n;};g-=1)while g>0}
100.times{|i|100.times{|j|r+=1 if [l[i][j],l[i+1][j],l[i][j+1],l[i+1][j+1]]==[1,1,1,1]}}
p r
