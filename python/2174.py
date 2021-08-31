A, B = map(int, input().split(" "))
N, M = map(int, input().split(" "))
field = [[0] * A for i in range(B)]
robots = []

dm = {
      "N": 0,
      "E": 1,
      "S": 2,
      "W": 3
}
dt = [(0, 1), (1, 0), (0, -1), (-1, 0)]

for i in range(N):
    x, y, d = input().split(" ")
    x, y, d = int(x) - 1, int(y) - 1, dm[d]
    robots.append([x, y, d])
    field[y][x] = i

issue = False
for _ in range(M):
    i, c, r = input().split(" ")
    i, r = int(i) - 1, int(r)

    if issue:
        continue

    for _ in range(r):
        if c == "L":
            robots[i][2] = robots[i][2] - 1 if robots[i][2] else 3
        elif c == "R":
            robots[i][2] = (robots[i][2] + 1) % 4
        else:
            x, y, d= robots[i]
            field[y][x] = 0
            dx, dy = dt[robots[i][2]]
            robots[i][0] += dx
            robots[i][1] += dy
            x, y, d = robots[i]
            if x < 0 or x == A or y < 0 or y == B:
                print("Robot {} crashes into the wall".format(i + 1))
                issue = True
                break
            elif field[y][x]:
                print("Robot {} crashes into robot {}".format(i + 1, field[y][x] + 1))
                issue = True
                break
            field[y][x] = i

if not issue:
    print("OK")