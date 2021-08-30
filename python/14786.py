import math
A, B, C = map(int, input().split(" "))
def f(x):
    return A * x + B * math.sin(x)

def df(x):
    return B * math.cos(x)

x0, x1 = 0, 100000
e = 10 ** -12
fx0, fx1 = f(x0), f(x1)
max_iteration = 1000000
i = 0
while abs(fx0 - C) > e and i < max_iteration:
    i += 1
    nx = (x0 + x1) / 2
    fnx = f(nx)
    if fnx > C:
        x1 = nx
    else:
        x0 = nx
    fx0 = f(x0)
print(x0)