n,k=map(int,input().split())
dp=[0 for i in range(k+100000)]
for i in range(n):
    x=int(input());dp[x]=1
    for j in range(k):
        if dp[j]:
            dp[j+x]=min(dp[j]+1,dp[j+x] if dp[j+x] else 2e9)
print(dp[k] if dp[k] else -1)
