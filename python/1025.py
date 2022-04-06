N, M = map(int, input().split())
L = []
m = -1
for i in range(N):
    L.append(list(input()))
for i in range(-N + 1, N):
    for j in range(-M + 1, M):
        for k in range(N):
            for l in range(M):
                if i == j == 0:
                    n = int(L[k][l])
                    if int(n ** 0.5) ** 2 == n:
                        m = max(m, n)
                    continue
                x, y = l, k
                s = ""
                while y >= 0 and x >= 0 and y < N and x < M:
                    s += L[y][x]
                    y += i
                    x += j
                    n = int(s)
                    if int(n ** 0.5) ** 2 == n:
                        m = max(m, n)
print(m)