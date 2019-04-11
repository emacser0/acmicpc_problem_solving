n,m=map(int,input().split())
ml=map(int,input().split())
q=[i+1 for i in range(n)]
qi=0
di=0
cnt=0
for i in ml:
 for j in range(len(q)):
  if q[j]==i:
   di=j
   break
 if di>qi:b,s=di,qi
 else:b,s=qi,di
 cnt+=min(b-s,s+len(q)-b)
 qi=di
 del q[qi]
print(cnt)
