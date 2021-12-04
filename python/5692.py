L = list(map(int, open(0)))
for N in L:
    if N == 0:
        break
    s = 0
    f = 1
    i = 0
    while N:
        f *= i + 1
        s += f * (N % 10)
        N //= 10
        i += 1
    print(s)