import functools

N = int(input()) 
L = [input() for i in range(N)]

def compare(x, y):
    lx, ly = len(x), len(y)
    if lx != ly:
        return [-1, 1][lx > ly]
    sx, sy = 0, 0
    for i in range(lx):
        sx += int(x[i]) if x[i].isdigit() else 0
        sy += int(y[i]) if y[i].isdigit() else 0
    if sx != sy:
        return [-1, 1][sx > sy]
    return [0, -1, 1][(x < y) + (x > y) * 2]

L.sort(key=functools.cmp_to_key(compare))
for s in L:
    print(s)