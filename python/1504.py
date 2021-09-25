import heapq
INPUT=lambda:map(int,input().split(" "))
N,E=INPUT()
g=[[0]*(N+1)for _ in range(N+1)]
for i in range(E):
 a,b,g[a][b]=INPUT()
 g[b][a]=g[a][b]
v1,v2=INPUT()
def D(s):
 q=[(0, s)]
 d=[9e9]*(N+1)
 d[s]=0
 while q:
  c,n=heapq.heappop(q)
  for i in range(1,N+1):
   if g[n][i]and c+g[n][i]<d[i]:
    d[i]=c+g[n][i];heapq.heappush(q,(d[i],i))
 return d
a=D(1)
d=D(v1)[v2]+min(a[v1]+D(v2)[N],a[v2]+D(v1)[N])
if d>=9e9:
 d=-1
print(d)