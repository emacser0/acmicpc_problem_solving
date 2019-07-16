N, M = map(int,input().split())
dp = [[0 for j in range(M + 1)] for i in range(N + 1)]
def calculate(n, r):
    global dp
    if dp[n][r]:
        return dp[n][r]
    elif n == r or r == 0:
        dp[n][r] = 1
        return 1
    else:
        dp[n][r] = calculate(n - 1, r - 1) + calculate(n - 1, r)
        return dp[n][r]

print(calculate(N, M))
