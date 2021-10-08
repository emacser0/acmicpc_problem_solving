N = int(input())
M = []
for i in range(N):
    M.append(list(input()))
    for j in range(N):
        if M[i][j] == '.':
            M[i][j] = 0

d = [(0, 1), (0, -1), (1, 0), (1, 1), (1, -1), (-1, 1), (-1, 0), (-1, -1)]

for y in range(N):
    for x in range(N):
        if type(M[y][x]) == int:
            continue
        M[y][x] = int(M[y][x])

        for dx, dy in d:
            cy, cx = y + dy, x + dx
            if cx >= 0 and cx < N and cy >= 0 and cy < N:
                if type(M[cy][cx]) != int:
                    continue
                M[cy][cx] += M[y][x]

        M[y][x] = '*'

for y in range(N):
    for x in range(N):
        if type(M[y][x]) == int and M[y][x] > 9:
            M[y][x] = 'M'
    print(''.join(list(map(str, M[y]))))