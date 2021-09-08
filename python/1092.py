[n],c,m,b=eval('sorted(map(int,input().split(" "))),'*4)
b.reverse()
t=0

while len(b)and max(c)>=max(b):
 for r in c:
  for i in b:
   if r>=i:b.remove(i);break
 t+=1
print(-1 if len(b) else t)