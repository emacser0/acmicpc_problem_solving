import math

N = int(input())
R = N // 2
cnt = 0
for x in range(1, R + 1):
    ph = (R ** 2 - (x - 1) ** 2) ** 0.5
    ch = (R ** 2 - x ** 2) ** 0.5

    cnt += math.ceil(ph) - math.floor(ch)

print(cnt * 4)