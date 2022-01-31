N, M = map(int, input().split())
ma, mb = 9e9, 9e9
for i in range(M):
    A, B = map(int, input().split())
    ma = min(ma, A)
    mb = min(mb, B)
print(min(ma * (N // 6 + 1), ma * (N // 6) + mb * (N % 6), mb * N))
