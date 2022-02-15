N, M = map(int, input().split())
r = 1
for n in map(int, input().split()):
    r *= n % M
    r %= M
print(r)