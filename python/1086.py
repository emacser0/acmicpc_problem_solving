from functools import *
from math import *
n = int(input())
l = []
for _ in range(n):
    l.append(int(input()))
k = int(input())

N = (1 << n) - 1
dp = [[0 for _ in range(k)] for _ in range(N + 1)]

ls = [len(str(l[i])) for i in range(n)]
dl = [reduce(lambda acc, i: acc + (ls[i] if v & 1 << i else 0), range(n), 0) for v in range(N + 1)]
dgl = [(10 ** i) % k for i in range(sum(ls))]
cache = []

for i in range(n):
    l[i] = l[i] % k
    dp[1 << i][l[i]] = 1

for i in range(N):
    for j in range(n):
        if i & 1 << j == 0:
            for m in range(k):
                dp[i | 1 << j][(m + l[j] * dgl[dl[i]]) % k] += dp[i][m]

cnt = dp[N][0]
if cnt == 0:
    print("0/1")
else:
    fac = factorial(n)
    g = gcd(cnt, fac)
    print("{}/{}".format(cnt // g, fac // g))