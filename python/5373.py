from itertools import *

T = int(input())

position_map = [
{
    (2, 0): (0, 0),
    (0, 0): (0, 2),
    (2, 2): (2, 0),
    (0, 2): (2, 2),
    (1, 0): (0, 1),
    (2, 1): (1, 0),
    (1, 2): (2, 1),
    (0, 1): (1, 2)
},
{
    (0, 0): (2, 0),
    (0, 2): (0, 0),
    (2, 0): (2, 2),
    (2, 2): (0, 2),
    (0, 1): (1, 0),
    (1, 0): (2, 1),
    (2, 1): (1, 2),
    (1, 2): (0, 1)
}]

rs = list(product([0, 1, 2], repeat=2))
rs.pop(rs.index((1, 1)))

for _ in range(T):
    n = int(input())
    m = list(input().split(" "))
    cube = [[[['w'] * 6 for _ in range(3)] for _ in range(3)] for _ in range(3)]
    for i, j in rs:
        cube[0][i][j][0] = 'w'
        cube[i][2][j][1] = 'r'
        cube[2][i][j][2] = 'y'
        cube[i][0][j][3] = 'o'
        cube[i][j][0][4] = 'g'
        cube[i][j][2][5] = 'b'
    for face, direction in m:
        direction = (direction == '+') if face in ['U', 'F', 'L'] else (direction != '+')
        index = 0 if face in ['U', 'B', 'L'] else 2
        replaced = [[['w'] * 6 for _ in range(3)] for _ in range(3)]
        if face in ['U', 'D']:
            for i, j in rs:
                i_n, j_n = position_map[direction][(i, j)]
                u, f, d, b, l, r = cube[index][i_n][j_n]
                replaced[i][j] = [u, r, d, l, f, b] if direction else [u, l, d, r, b, f]
            for i, j in rs:
                cube[index][i][j] = replaced[i][j]
        elif face in ['F', 'B']:
            for i, j in rs:
                i_n, j_n = position_map[direction][(i, j)]
                u, f, d, b, l, r = cube[i_n][index][j_n]
                replaced[i][j] = [l, f, r, b, d, u] if direction else [r, f, l, b, u, d]
            for i, j in rs:
                    cube[i][index][j] = replaced[i][j]
        elif face in ['L', 'R']:
            for i, j in rs:
                i_n, j_n = position_map[direction][(i, j)]
                u, f, d, b, l, r = cube[i_n][j_n][index]
                replaced[i][j] = [b, u, f, d, l, r] if direction else [f, d, b, u, l, r]
            for i, j in rs:
                cube[i][j][index] = replaced[i][j]
    for i in range(3):
        for j in range(3):
            print(cube[0][i][j][0], end='')
        print("")