board = []
zeros = []
for y in range(9):
    row = list(map(int, list(input())))
    for x in range(9):
        if row[x] == 0:
            zeros.append((y, x))
    board.append(row)

zl = len(zeros)

av = [[0] * 10 for _ in range(zl)]

def available(n, y, x):
    yoff, xoff = y // 3 * 3, x // 3 * 3
    for i in range(9):
        if board[yoff + i // 3][xoff + i % 3] == n:
            return False
        if board[y][i] == n or board[i][x] == n:
            return False
    return True

for i in range(zl):
    for j in range(1, 10):
        av[i][j] = available(j, *zeros[i])

def solve(i):
    if i == zl:
        for j in range(9):
            print(*board[j], sep="")
        return True
    y, x = zeros[i]
    updated = False
    for j in range(1, 10):
        if av[i][j]:
            board[y][x], o = j, board[y][x]

            unavailable = []
            for k in range(i + 1, zl):
                zy, zx = zeros[k]
                if av[k][j] and \
                   (zy == y or zx == x or (y // 3 == zy // 3 and x // 3 == zx // 3)):
                    av[k][j] = 0
                    unavailable.append(k)

            if solve(i + 1):
                return True

            board[y][x] = o
            for ui in unavailable:
                av[ui][j] = 1
    return False

solve(0)