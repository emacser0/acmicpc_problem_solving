n = int(input())
a = list(map(int, input().split(" ")))
a.sort()
minv = abs(a[0] + a[1] + a[2])
minl, minm, minr = 0, 1, 2
for m in range(n):
    l, r = 0 if m != 0 else 1, n - 1 if m != n - 1 else n - 2
    while l < r and l != m and r != m:
        v = a[l] + a[r] + a[m]
        if minv > abs(v):
            minv = abs(v)
            minl, minm, minr = l, m, r
        if v == 0:
            break
        if v < 0:
            l += 1
        else:
            r -= 1

print(*sorted([a[minl], a[minm], a[minr]]))