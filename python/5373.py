from itertools import *

T = int(input())

position_table = [
    [[0, 2], [1, 2], [2, 2]],
    [[0, 1], [1, 1], [2, 1]],
    [[0, 0], [1, 0], [2, 0]]
]

rotate_table = [
    [[0, 4, 2, 5, 3, 1], [0, 5, 2, 4, 1, 3]],
    [[5, 1, 4, 3, 0, 2], [4, 1, 5, 3, 2, 0]],
    [[1, 2, 3, 0, 4, 5], [3, 0, 1, 2, 4, 5]]
]

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
        table_index = 0 if face in ['U', 'D'] else (1 if face in ['F', 'B'] else 2)
        replaced = [[['w'] * 6 for _ in range(3)] for _ in range(3)]
        for i, j in rs:
            a, b = (2 - i, 2 - j) if direction else (i, j)
            i_n, j_n = position_table[a][b]
            a, b, c = ((i_n, index, j_n) if table_index < 2 else (i_n, j_n, index)) if table_index else (index, i_n, j_n)
            replaced[i][j] = [cube[a][b][c][rotate_table[table_index][direction][k]] for k in range(6)]
        for i, j in rs:
            a, b, c = ((i, index, j) if table_index < 2 else (i, j, index)) if table_index else (index, i, j)
            cube[a][b][c] = replaced[i][j]
    for i in range(3):
        for j in range(3):
            print(cube[0][i][j][0], end='')
        print("")