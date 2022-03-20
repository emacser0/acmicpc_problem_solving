N, M = map(int, input().split())
L = list(map(int, input().split()))

cnt = 0
for i in range(N):
    if sum(L[i:N]) < M:
        break
    for j in range(i + 1, N + 1):
        s = sum(L[i:j])
        if s == M:
            cnt += 1
        elif s > M:
            break
print(cnt)