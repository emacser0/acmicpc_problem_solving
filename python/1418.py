n, k = eval('int(input()),' * 2)

p = [1 for _ in range(n + 1)]

for i in range(2, n + 1):
    j = 2
    while i * j <= n:
        p[i * j] = 0
        j += 1

s = 0
for i in range(1, n + 1):
    e = p[i] and i > k
    j = 1
    while j * j <= i:
        e |= p[j] and j > k and i % j == 0
        e |= p[i // j] and (i // j) > k and i % j == 0
        j += 1
    s += not e

print(s)