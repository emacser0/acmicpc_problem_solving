L =[]

for i in range(10):
    s = list(input())
    for i in [7, 4, 1]:
        s.pop(i)
    L.append(s)

for i in [7, 4, 1]:
    L.pop(i)

A, B = 0, 14
for i in range(7):
    for j in range(7):
        A += i % 2 != j % 2 and L[i][j] == '.'

for y in range(0, 6, 2):
    for x in range(0, 6, 2):
        for (i, j) in [(0, 1), (1, 2)]:
            if '.' in [L[y + i][x + j], L[y + j][x + i]]:
                B -= 1
                break

for y in range(0, 4, 2):
    for x in range(0, 4, 2):
        for (i, j) in [(0, 1), (0, 3), (1, 4), (3, 4)]:
            if '.' in [L[y + i][x + j], L[y + j][x + i]]:
                B -= 1
                break

for (i, j) in [(0, 1), (0, 3), (0, 5), (6, 1), (3, 6), (5, 6)]:
    if '.' in [L[i][j], L[j][i]]:
        B -= 1
        break

print(A, B)