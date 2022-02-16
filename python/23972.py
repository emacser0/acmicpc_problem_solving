import math
K, N = map(int, input().split())
if N == 1:
    print(-1)
else:
    x = K * N // (N - 1)
    print([x, x + 1][(x - K) * N < x])