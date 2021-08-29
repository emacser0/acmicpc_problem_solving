n, m = map(int, input().split(" "))
square = []
for i in range(n):
    square.append([*map(int,list(input()))])


def get_max_product(ra, rb, range_generator):
    mp = 0
    for i in ra:
        for j in rb:
            ranges = range_generator(i, j)
            sums = [0, 0, 0]
            for ri in range(3):
                ry, rx = ranges[ri]
                for k in ry:
                    for l in rx:
                        sums[ri] += square[k][l]
            mp = max(mp, sums[0] * sums[1] * sums[2])
    return mp

def rp(a, b, c, d):
    return (range(a, b), range(c, d))

rs = [rp(1, n, 1, m), rp(1, n, 1, n), rp(1, m, 1, m), rp(1, n, 1, m), rp(1, n, 1, m), rp(1, n, 1, m)]
rgs = [lambda i, j: [rp(0, i, 0, j), rp(i, n, 0, j), rp(0, n, j, m)], \
       lambda i, j: [rp(0, i, 0, m), rp(i, j, 0, m), rp(j, n, 0, m)], \
       lambda i, j: [rp(0, n, 0, i), rp(0, n, i, j), rp(0, n, j, m)], \
       lambda i, j: [rp(0, n, 0, j), rp(0, i, j, m), rp(i, n, j, m)], \
       lambda i, j: [rp(0, i, 0, j), rp(0, i, j, m), rp(i, n, 0, m)], \
       lambda i, j: [rp(0, i, 0, m), rp(i, n, 0, j), rp(i, n, j, m)]]

mp = 0
for i in range(6):
    mp = max(mp, get_max_product(*rs[i], rgs[i]))
print(mp)