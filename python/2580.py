m=[]
for i in range(9):
    m+=[list(map(int,input().split()))]
seq=[]
e=0
for i in range(9):
    for j in range(9):
        if m[j][i]==0:
            seq+=[[i,j]]
def dfs(x):
  global e
  if e==1:return
  if x==len(seq) and e==0:
      for i in range(9):
          print(" ".join(str(x) for x in m[i]))
      e=1
      return
  c=[0 for i in range(10)]
  for i in range(9):
      c[m[i][seq[x][0]]]+=1;c[m[seq[x][1]][i]]+=1
  a,b=int(seq[x][0]/3)*3,int(seq[x][1]/3)*3
  for i in range(3):
      for j in range(3):
          c[m[b+j][a+i]]+=1
  for i in range(1,10):
      if c[i]==0 and e==0:
          m[seq[x][1]][seq[x][0]]=i
          dfs(x+1)
          m[seq[x][1]][seq[x][0]]=0
dfs(0)
