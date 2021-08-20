import math
x1, y1, x2, y2 = map(int, input().split(" "))
x3, y3, x4, y4 = map(int, input().split(" "))

ccwA = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1)
ccwB = (x2 - x1) * (y4 - y1) - (y2 - y1) * (x4 - x1)

ccwC = (x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3)
ccwD = (x4 - x3) * (y2 - y3) - (y4 - y3) * (x2 - x3)

d13 = (x1 - x3) ** 2 + (y1 - y3) ** 2
d14 = (x1 - x4) ** 2 + (y1 - y4) ** 2
d23 = (x2 - x3) ** 2 + (y2 - y3) ** 2
d24 = (x2 - x4) ** 2 + (y2 - y4) ** 2

if d13 < d23:
    x1, y1, x2, y2 = x2, y2, x1, y1

if d23 > d24:
    x3, y3, x4, y4 = x4, y4, x3, y3

if ccwA * ccwB <= 0 and ccwC * ccwD <= 0:
    if ccwA == ccwB == ccwC == ccwD == 0:
        d14 = math.sqrt((x1 - x4) ** 2 + (y1 - y4) ** 2)
        d12 = math.sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2)
        d34 = math.sqrt((x3 - x4) ** 2 + (y3 - y4) ** 2)
        print(d14 <= d12 + d34)
    else:
        print(1)
else:
    print(0)