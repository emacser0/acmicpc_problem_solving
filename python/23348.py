A, B, C = map(int, input().split(" "))
N = int(input())
m = 0
for i in range(N):
    s = 0
    for j in range(3):
        a, b, c = map(int, input().split(" "))
        s += a * A + b * B + c * C
    m = max(m, s)
print(m)