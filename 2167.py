n,m=map(int,input().split())
l=[]
for i in range(n):
    l+=[list(map(int,input().split()))]
dp=[[0]*m for i in range(n)]
dp[0][0]=l[0][0]
for i in range(0,n):
    for j in range(0,m):
        dp[i][j]=(dp[i-1][j] if i>0 else 0)+(dp[i][j-1] if j>0 else 0)-(dp[i-1][j-1] if i>0 and j>0 else 0)+l[i][j]
k=int(input())
for i in range(k):
    i,j,x,y=map(int,input().split())
    i,j,x,y=i-1,j-1,x-1,y-1
    print(dp[x][y]-(dp[x][j-1] if j>0 else 0)-(dp[i-1][y] if i>0 else 0)+(dp[i-1][j-1] if i>0 and j>0 else 0))
