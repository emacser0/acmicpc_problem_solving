from itertools import *
def solve():
    N = int(input())
    m = []
    m.append([0 for i in range(N + 2)])
    for i in range(1, N + 1):
        m.append([0] + list(input()) + [0])
        for j in range(1, N + 1):
            if m[i][j].isdigit():
                m[i][j] = int(m[i][j])
    m.append([0 for i in range(N + 2)])
    if N < 3:
        print(0)
        return;
    if N == 3:
        if m[1][1] > 0:
            print(1)
        else:
            print(0)
        return;
    cnt = 0
    
    for i in range(1, N + 1):
        for j in range(1, N + 1):
            if type(m[i][j]) != int:
                continue

            for k in range(-1, 2):
                for l in range(-1, 2):
                    if type(m[i + k][j + l]) == int:
                        continue
                    if m[i][j] == 0:
                        m[i + k][j + l] = " "
                        continue
                    if m[i + k][j + l] == '#':
                        m[i + k][j + l] = "?"
                    elif m[i + k][j + l] == '?':
                        m[i][j] -= 1
                        m[i + k][j + l] = '*'
                        cnt += 1
                    elif m[i + k][j + l] == '*':
                        m[i][j] -= 1
    print(cnt + (N - 4) ** 2)
solve()
