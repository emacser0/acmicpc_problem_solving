from itertools import *

n = int(input())

def search():
    for c in permutations([i for i in range(10)], 7):
        d, e, h, l, o, r, w = c
        if h == 0 or w == 0:
            continue

        up = h * 10 ** 4 + e * 10 ** 3 + l * 10 ** 2 + l * 10 + o
        down = w * 10 ** 4 + o * 10 ** 3 + r * 10 ** 2 + l * 10 + d
        r = up + down

        if r == n:
            print("  " + str(up))
            print("+ " + str(down))
            print("-------")
            print(" " + (" " if len(str(r)) == 5 else "") + str(r))
            return

    print("No Answer")

search()