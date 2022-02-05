N, M = map(int, input().split())
s2, s5 = 0, 0
r = 2
while N >= r:
    s2 += (N // r) - ((N - M) // r) - (M // r)
    r *= 2
r = 5
while N >= r:
    s5 += (N // r) - ((N - M) // r) - (M // r)
    r *= 5
print(min(s2, s5))