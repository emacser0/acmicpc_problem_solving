H, M, S = map(int, input().split(" "))
Q = int(input())
s = H * 3600 + M * 60 + S
for i in range(Q):
    L = list(map(int, input().split(" ")))
    T = L[0]

    if T == 1:
        C = L[1]
        s += C
    elif T == 2:
        C = L[1]
        s -= C
    else:
        print(s // 3600, (s % 3600) // 60, (s % 3600) % 60)

    if s < 0:
        s += 86400

    s = s % 86400