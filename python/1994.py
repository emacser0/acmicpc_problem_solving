n = int(input())

L = set()
d = {}
for i in range(n):
    t = int(input())
    L.add(t)
    if t not in d:
        d[t] = 0
    d[t] += 1

mc = 0
for cnt in d.values():
    mc = max(mc, cnt)

L = list(L)
L.sort()

n = len(L)

def search(d, p, l, r):
    while l < r:
        i = (l + r) // 2
        if L[i] - L[p] < d:
            l = i + 1
        else:
            r = i
    return r


for i in range(n):
    if mc > n - i:
        break
    for j in range(i + 1, n):
        d = L[j] - L[i]
        k = j
        cnt = 2
        while k < n:
            r = search(d, k, k + 1, n - 1)
            if k < r < n and L[r] - L[k] == d:
                cnt += 1
                k = r
                continue
            break
        mc = max(mc, cnt)

print(mc)