N, L, W, H = map(int, input().split())
l, r = 0, max(L, W, H)

for i in range(10000):
    m = (l + r) / 2
    s = (L // m) * (W // m) * (H // m)
    if s >= N:
        l = m
    else:
        r = m

print(r)