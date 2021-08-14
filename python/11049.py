n = int(input())
matrices = []
for i in range(n):
    r, c = map(int, input().split(' '))
    matrices.append((r, c))

def calc(a, b):
    return matrices[a][0] * matrices[a][1] * matrices[b][1]

def solve():
    if n == 1:
        print("0")
        return
    maxd = 2 ** 31 - 1
    dp = [[maxd] * n for _ in range(n)]

    for i in range(n):
        dp[i][i] = 0

    for i in range(1, n):
        for j in range(0, n):
            if j + i >= n:
                break
            for k in range(j, j + i):
                dp[j][j + i] = min(dp[j][j + i], dp[j][k] + dp[k + 1][j + i] + matrices[j][0] * matrices[k][1] * matrices[j + i][1])

    print(dp[0][n - 1])

solve()