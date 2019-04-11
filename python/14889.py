n=int(input())
s=[[int(x)for x in input().split()]for x in range(n)]
m=2e9
def c(l):
 r=0
 for i in l:
  for j in l:r+=s[i][j]
 return r
def d(x,a,b):
 global m
 if x==n and len(a)==n/2:m=min(m,abs(c(a)-c(b)))
 elif x!=n:d(x+1,a+[x],b),d(x+1,a,b+[x])
d(0,[],[])
print(m)
