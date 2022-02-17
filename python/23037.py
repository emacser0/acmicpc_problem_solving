N = int(input())
r = 0
while N:
    r += (N % 10) ** 5
    N //= 10
print(r)
