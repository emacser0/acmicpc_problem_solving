A, B = map(int, input().split(" "))

a, b = 0, 0
for x in range(A, B + 1, A):
    if x ** 2 > A * B:
        break
    y = int(A * B / x)
    m, n = x, y
    while n > 0:
        m, n = n, m % n
    if x * y / m != B:
        continue
    a, b = x, y
print(a, b)
