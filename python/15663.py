from itertools import *
_, m = map(int ,input().split(' '))
l = list(map(int, list(input().split(' '))))
l = list(set(list(permutations(l, m))))
l.sort()
l = map(lambda x: list(map(str, x)), l)
*starmap(print, l),
