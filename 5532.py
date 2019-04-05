from math import ceil
l,a,b,c,d=[int(input()) for x in range(5)]
print(l-max(ceil(a/c),ceil(b/d)))
