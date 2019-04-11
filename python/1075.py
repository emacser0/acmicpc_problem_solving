n=int(int(input())/100)*100
f=int(input())
for i in range(f-1):
    if not (n+i)%f:print("%02d"%i);break
