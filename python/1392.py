N, Q = map(int, input().split(" "))
T = []
for i in range(N):
    T.append(int(input()))
    if i > 0:
        T[i] += T[i - 1]

for _ in range(Q):
    q = int(input())
    i = 0
    for t in T:
        if t > q:
            break
        i += 1

    print(i + 1)