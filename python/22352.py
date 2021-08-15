n, m = map(int, input().split(" "))
before = [list(map(int, input().split(" "))) for _ in range(n)]
after = [list(map(int, input().split(" "))) for _ in range(n)]
group = [[0] * m for _ in range(n)]

directions = [(1, 0), (0, 1), (-1, 0), (0, -1)]

def make_group(x, y):
    for dx, dy in directions:
        if x + dx >= 0 and x + dx < m and y + dy >= 0 and y + dy < n:
            if before[y][x] == before[y + dy][x + dx] and group[y + dy][x + dx] == 0:
                group[y + dy][x + dx] = group[y][x]
                make_group(x + dx, y + dy)

gi = 1

for i in range(n):
    for j in range(m):
        if group[i][j] == 0:
            group[i][j] = gi
            make_group(j, i)
            gi += 1


def check():
    updated = 0
    for i in range(n):
        for j in range(m):
            if before[i][j] != after[i][j]:
                if updated > 0 and updated != group[i][j]:
                    return False
                updated = group[i][j]
            for dx, dy in directions:
                if j + dx >= 0 and j + dx < m and i + dy >= 0 and i + dy < n:
                    if group[i][j] == group[i + dy][j + dx] and after[i][j] != after[i + dy][j + dx]:
                        return False
    return True

print("YES" if check() else "NO")