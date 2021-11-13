x1, y1, x2, y2, x3, y3 = map(int, input().split(" "))

def distance(x1, y1, x2, y2):
    return ((x1 - x2) ** 2 + (y1 - y2) ** 2) ** 0.5

if x2 - x1 == 0:
    d1 = 9e9
else:
    d1 = (y2 - y1) / (x2 - x1)
if x3 - x1 == 0:
    d2 = 9e9
else:
    d2 = (y3 - y1) / (x3 - x1)

if d1 == d2:
    print(-1)
else:
    d1 = distance(x1, y1, x2, y2)
    d2 = distance(x1, y1, x3, y3)
    d3 = distance(x2, y2, x3, y3)

    a = d1 * 2 + d2 * 2
    b = d1 * 2 + d3 * 2
    c = d2 * 2 + d3 * 2

    print(max(a, b, c) - min(a, b, c))