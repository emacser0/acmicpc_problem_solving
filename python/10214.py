t=int(input())
for i in range(t):
    a,b=0,0
    for j in range(9):
        x,y=map(int,input().split())
        a+=x;b+=y
    print("Yonsei" if a>b else "Draw" if a==b else "Korea")
