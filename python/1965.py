N = int(input())
L = list(map(int, input().split()))

dp = [1 for i in range(N)]
for i in range(1, N):
    for j in range(0, i):
        if L[i] > L[j]:
            dp[i] = max(dp[i], dp[j] + 1)

print(max(dp))