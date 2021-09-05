from functools import *
from math import *
n = int(input())
l = []
for _ in range(n):
    l.append(int(input()))
k = int(input())

dp = [[] for _ in range(n)]

def get_digit(v):
    return reduce(lambda acc, i: acc + (len(str(l[i])) if v & 1 << i else 0), range(n), 0)

for i in range(n):
    if l[i] % k == 0:
        dp[0].append(1 << i)

for i in range(1, n):
    for v in dp[i - 1]:
        d = 10 ** get_digit(v)
        for j in range(n):
            if v & 1 << j == 0 and (l[j] * d) % k % k == 0:
                dp[i].append(v | 1 << j)

cnt = len(dp[n - 1])
if cnt == 0:
    print("0/1")
else:
    fac = factorial(n)
    g = gcd(cnt, fac)
    print("{}/{}".format(cnt // g, fac // g))