n = int(input())

c = [0 for _ in range(1000001)]
l = []
for i in range(n):
    m = int(input())
    l.append(m)
    c[m] += 1

d = [0 for _ in range(n)]
for i in range(n):
    for j in range(1, int(l[i] ** (1/2)) + 1):
        if l[i] % j == 0:
            d[i] += c[j]
            v = l[i] // j
            if j != v:
                d[i] += c[v]
    print(d[i] - 1)