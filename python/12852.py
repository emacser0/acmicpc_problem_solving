N = int(input())

q = [[1]]

M = 10 ** 10
t = [[M] for _ in range(N + 1)]
t[1] = [0]
for n in range(1, N):
    t[n][0] += 1
    if n * 3 <= N and t[n * 3][0] > t[n][0]:
        t[n * 3] = t[n] + [n]
    if n * 2 <= N and t[n * 2][0] > t[n][0]:
        t[n * 2] = t[n] + [n]
    if t[n + 1][0] > t[n][0]:
        t[n + 1] = t[n] + [n]
t[N].append(N)
print(t[N][0])
print(*reversed(t[N][1:]))