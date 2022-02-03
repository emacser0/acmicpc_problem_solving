N, L = map(int, input().split())
r = []
for l in range(L, 101):
    A = 2 * N + l * (1 - l)
    if A % (2 * l) or A < 0:
        continue
    A //= 2 * l
    r = [str(i) for i in range(A, A + l)]
    break
print(' '.join(r) if r else -1, sep=' ')