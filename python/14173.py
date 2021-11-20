(x1, y1, x2, y2), (x3, y3, x4, y4) = eval("map(int, input().split())," * 2)
x = [x1, x2, x3, x4]
y = [y1, y2, y3, y4]
print(max(max(x) - min(x), max(y) - min(y)) ** 2)