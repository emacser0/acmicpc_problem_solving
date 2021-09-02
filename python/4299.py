a, b = map(int, input().split(" "))
x = (a + b) // 2
y = a - x
if a < b or x + y != a or x - y != b:
    print(-1)
else:
    print(x, y)