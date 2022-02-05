N = int(input())
S = input()
d = 2
x, y = 0, 0
w = 1
h = 1
map = [[1]]
for ch in S:
    if ch == "R":
        d = (d + 1) % 4
    elif ch == "L":
        d = d - 1 if d > 0 else 3
    elif ch == "F":
        x, y = [(x, y - 1), (x + 1, y), (x, y + 1), (x - 1, y)][d]
        if x < 0:
            for i in range(h):
                map[i].insert(0, 0)
            x += 1
            w += 1
        if y < 0:
            map.insert(0, [0] * w)
            y += 1
            h += 1
        if x >= w:
            for i in range(h):
                map[i].append(0)
            w += 1
        if y >= h:
            map.append([0] * w)
            h += 1
        map[y][x] = 1
for i in range(h):
    for j in range(w):
        print(['#', '.'][map[i][j]], end='')
    print("")