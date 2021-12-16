N = int(input())
s = 0
for i in range(1, N + 1):
    j = i
    while i * j <= N:
        s += 1
        j += 1
print(s)