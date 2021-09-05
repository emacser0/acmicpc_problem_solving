from itertools import *
from functools import *
from math import *
n = int(input())
l = []
for _ in range(n):
    l.append(int(input()))
k = int(input())

cnt = 0
for p in permutations(l, r=2):
    s = reduce(lambda acc, x: acc + str(x), p, "")
    if int(s) % k == 0:
        print(s)
        cnt += 1

if cnt == 0:
    print("0/1")
else:
    fac = factorial(n)
    g = gcd(cnt, fac)
    print("{}/{}".format(cnt // g, fac // g))
