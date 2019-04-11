while 1:
 p=[]
 q=0
 while 1:
  s=input()
  if s[:4]=="QUIT":q=1;break
  elif s[:3]=="END":break
  p+=[s]
 if q:break
 n=int(input())
 for i in range(n):
  s=[int(input())]
  e=0
  for j in p:
   op=j[:3]
   l=len(s)
   if op=="NUM":
    od=int(j[4:])
    if od>=0 and od<=10**9:s.insert(0,int(j[4:]))
    else:e=1
   elif op=="POP":
    if l:del s[0]
    else:e=1
   elif op=="INV":
    if l:s[0]=-s[0]
    else:e=1
   elif op=="DUP":
    if l:s.insert(0,s[0])
    else:e=1
   elif op=="SWP":
    if l>1:s[0],s[1]=s[1],s[0]
    else:e=1
   elif op=="ADD":
    if l>1:
     r=s[1]+s[0];
     if abs(r)<=10**9:s[1]=r;del s[0]
     else:e=1
    else:e=1
   elif op=="SUB":
    if l>1:
     r=s[1]-s[0];
     if abs(r)<=10**9:s[1]=r;del s[0]
     else:e=1
    else:e=1
   elif op=="MUL":
    if l>1:s[1]*=s[0];del s[0]
    else:e=1
   elif op=="DIV":
    if l>1 and s[0]!=0:
     g=1 if(s[0]>0 and s[1]>0)or(s[0]<0 and s[1]<0)else -1
     r=g*int(abs(s[1])/abs(s[0]))
     s[1]=r;del s[0]
    else:e=1
   elif op=="MOD":
    if l>1 and s[0]!=0:
     g=1 if s[1]>0 else -1
     s[1]=g*(abs(s[1])%abs(s[0]))
     del s[0]
    else:e=1
  if len(s)==1 and e==0 and abs(s[0])<=10**9:print(s[0])
  else:print("ERROR")
 print('')
