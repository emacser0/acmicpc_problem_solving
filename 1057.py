n=int(input())
dp=[1,1,1,1,1,1,1,1,1,1]
for i in range(1,n):
    ndp=[0 for i in range(10)]
    s=sum(dp)
    for j in range(10):
        ndp[j]=s%10007
        s-=dp[j]
    dp=ndp
sum=0
for i in dp:
    sum+=i
print(sum%10007)
