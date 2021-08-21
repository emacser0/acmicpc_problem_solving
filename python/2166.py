n = int(input())

points = []
for i in range(n):
    points.append(tuple(map(int, input().split(" "))))

S = 0
for i in range(n - 1):
    S += points[i][0] * points[i + 1][1] - points[i][1] * points[i + 1][0]

S += points[n - 1][0] * points[0][1] - points[n - 1][1] * points[0][0]

print("{:.1f}".format(abs(S / 2)))