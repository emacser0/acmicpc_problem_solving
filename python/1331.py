def isValid():
    sx, sy = -1, -1
    px, py = -1, -1
    m = [[0 for j in range(6)] for i in range(6)]
    for i in range(36):
        S = input()

        x, y = ord(S[0]) - ord('A'), int(S[1]) - 1
        dx, dy = abs(x - px), abs(y - py)
        px, py = x, y

        m[y][x] = 1

        if i == 0:
            sx, sy = x, y
            continue

        if {dx, dy} != {1, 2}:
            return False

    if {abs(x - sx), abs(y - sy)} != {1, 2}:
        return False

    return sum(map(sum, m)) == 36

print(["Invalid", "Valid"][isValid()])