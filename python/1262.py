N, R1, C1, R2, C2 = map(int, input().split())
def getChr(n, y, x):
    r = y % (2 * n - 1)
    c = x % (2 * n - 1)
    o = ord('a') + abs(n - 1 - r) + abs(n - 1 - c)
    if o < ord('a') or o >= ord('a') + n:
        o = ord('.')
    else:
        o = (o - ord('a')) % 26 + ord('a')
    return o

for y in range(R1, R2 + 1):
    for x in range(C1, C2 + 1):
        print(chr(getChr(N, y, x)), end='')
    print("")