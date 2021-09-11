N, L, D = map(int, input().split(" "))
n, l, d = N, L, 0

T = 0
t = 0
while n:
    if T and d == 0:
        break

    if T:
        T -= 1
    else:
        l -= 1

    if l == 0:
        n -= 1
        l = L
        T = 5

    d = d + 1
    if d == D:
        d = 0

    t += 1

print(t + (D - d if d > 0 else 0))