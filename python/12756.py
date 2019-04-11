a,b=map(int,input().split())
c,d=map(int,input().split())
while b>0 and d>0:b,d=b-c,d-a
if b<=0 and d<=0:print("DRAW")
else:print("PLAYER " + ("A" if b>0 and d<=0 else "B"))
