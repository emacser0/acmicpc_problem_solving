n = int(input())
a = list(map(int, input().split(" ")))
l, r = 0, n - 1
minv = abs(a[l] + a[r])
minl, minr = l, r
while l < r:
    v = a[l] + a[r]
    if minv > abs(v):
        minv = abs(v)
        minl, minr = l, r
    if v == 0:
        break
    if v < 0:
        l += 1
    else:
        r -= 1

print(a[minl], a[minr])