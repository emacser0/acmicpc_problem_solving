from itertools import *
_, m = map(int ,input().split(' '))
l = list(map(int, list(input().split(' '))))
l = list(combinations_with_replacement(l, r=m))
l = list(map(lambda x: tuple(sorted(x)), l))
l = sorted(list(set(l)))
l = map(lambda x: list(map(str, x)), l)
*starmap(print, l),
