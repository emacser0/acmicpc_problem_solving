from functools import *

T = int(input())

def get_first_divisor(n):
    i = 2
    while i * i <= n:
        if n % i == 0:
            return i
        i += 1
    return n

def divide(n, l):
    divisor = get_first_divisor(n)
    if divisor < n:
        l.append(divisor)
        return divide(n // divisor, l)
    l.append(n)
    return l


for t in range(T):
    n, m = map(int, input().split(" "))
    a, b = [], []
    for v in map(int, input().split(" ")):
        if v > 1:
            a.append(v)
    for v in map(int, input().split(" ")):
        if v > 1:
            b.append(v)

    ad = []
    for v in a:
        ad += divide(v, [])

    bd = []
    for v in b:
        bd += divide(v, [])

    for i, d in enumerate(ad):
        if bd.count(d):
            ad[i] = 0
            bd.remove(d)

    while ad.count(0):
        ad.remove(0)

    print("Case #{}: {} / {}".format(
        t + 1,
        reduce(lambda acc, x: acc * x, ad, 1),
        reduce(lambda acc, x: acc * x, bd, 1)
    ))