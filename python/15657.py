from itertools import *
_, m = map(int ,input().split(' '))
l = list(map(int, input().split(' ')))
l.sort()
*starmap(print, list(combinations_with_replacement(l, r=m))),
