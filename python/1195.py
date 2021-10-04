a=input()
b=input()
v,w=len(a),len(b)
m=v+w
for o in range(0,v):
 p=1
 for i in range(0, min(v-o,w)):
  if a[i+o]==b[i]=="2":
   p=0
   break
 if p:
  m=max(v,w+o)
  break
for o in range(0,w):
 p=1
 for i in range(0, min(v,w-o)):
  if b[i+o]==a[i]=="2":
   p=0
   break
 if p:
  m=min(m,max(w,v+o))
  break
print(m)