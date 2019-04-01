t=int(input())
for i in range(t):
    n=int(input())
    dp=[1,1,1,2,2]
    for i in range(5,n):
        dp+=[dp[i-1]+dp[i-5]]
    print(dp[n-1])
