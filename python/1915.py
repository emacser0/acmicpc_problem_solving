n, m = map(int, input().split(" "))
board = []
for _ in range(n):
    board.append([*map(int, list(input()))])

dp = [[0] * m for _ in range(n)]
dp[0][0] = board[0][0]
maxarea = 0
for i in range(n):
    for j in range(m):
        if board[i][j] == 0:
            continue
        dp[i][j] = 1
        if i > 0 and j > 0:
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1
        maxarea = max(dp[i][j], maxarea)
print(maxarea ** 2)