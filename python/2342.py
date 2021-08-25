from itertools import *
c = list(map(int, input().split(" ")))
n = len(c) - 1
M = 10 ** 10
dp = [[[M] * 5 for _ in range(5)] for _ in range(n)]
p = list(permutations([0, 1, 2, 3, 4], r=2))

def get_force(a, b):
    if a == b:
        return 1
    if a == 0:
        return 2
    if a % 2 == b % 2:
        return 4
    return 3

dp[0][0][c[0]] = 2
dp[0][c[0]][0] = 2
for i in range(1, n):
    for j, k in p:
        if dp[i - 1][j][k] == M:
            continue
        if j != c[i]:
            dp[i][j][c[i]] = min(dp[i][j][c[i]], dp[i - 1][j][k] + get_force(k, c[i]))
        if k != c[i]:
            dp[i][c[i]][k] = min(dp[i][c[i]][k], dp[i - 1][j][k] + get_force(j, c[i]))
mr = M
for j, k in p:
    mr = min(mr, dp[n - 1][j][k])
print(mr)