import operator as op
from functools import reduce

def ncr(n, r):
    r = min(r, n-r)
    numer = reduce(op.mul, range(n, n-r, -1), 1)
    denom = reduce(op.mul, range(1, r+1), 1)
    return numer // denom

n = int(input())

v = 5 + n - 1
s = 0
for i in range(0, n):
    if v % 3 == 0:
        while(i < n):
            s += ncr(n - 1, i)
            i += 3
        break
    v += 4
print(s % 1000000007)