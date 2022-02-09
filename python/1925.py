x1, y1 = map(int, input().split())
x2, y2 = map(int, input().split())
x3, y3 = map(int, input().split())

e = sorted([
    (x1 - x2) ** 2 + (y1 - y2) ** 2,
    (x2 - x3) ** 2 + (y2 - y3) ** 2,
    (x3 - x1) ** 2 + (y3 - y1) ** 2
])

if (x3 - x1) * (y2 - y1) - (y3 - y1) * (x2 - x1) == 0:
    print("X")
elif e[0] == e[1] == e[2]:
    print("JungTriangle")
else:
    print(["Dunkak", "Jikkak", "Yeahkak"][(e[0] + e[1] == e[2]) + (e[0] + e[1] > e[2]) * 2] +
          ["", "2"][e[0] == e[1] or e[1] == e[2]] + "Triangle")