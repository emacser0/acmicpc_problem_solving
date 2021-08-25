n = int(input())
street = []
for _ in range(n):
    street.append([*map(int, input().split(" "))])

M = 10 ** 10
dp = [[M, M, M] for _ in range(n)]
r = M

for a, b, c in [[0, 1, 2], [1, 0, 2], [2, 0, 1]]:
    dp[0] = [street[0][a], street[0][a], street[0][a]]
    dp[1][a] = M
    dp[1][b] = dp[0][a] + street[1][b]
    dp[1][c] = dp[0][a] + street[1][c]
    for i in range(2, n):
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + street[i][0]
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + street[i][1]
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + street[i][2]
    r = min(r, dp[i][b], dp[i][c])
print(r)