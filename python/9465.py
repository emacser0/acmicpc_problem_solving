t=int(input())
for i in range(t):
    n,a,b=int(input()),list(map(int,input().split())),list(map(int,input().split()))
    p,x,y=0,a[0],b[0]
    for i in range(1,n):p,x,y=max(x,y),max(y,p)+a[i],max(x,p)+b[i]
    print(max(x,y))
