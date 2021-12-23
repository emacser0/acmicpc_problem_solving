N = int(input())
d = 0
a = 1
s = 0
while s <= N:
    a += d
    d += 4
    s += a
print(d // 4 - 1)