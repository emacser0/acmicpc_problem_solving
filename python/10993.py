from itertools import *
n = int(input())

def star(stars, n, xoff, yoff):
    width, height = (2 ** n - 1) * 2 - 1, 2 ** n - 1
    xcenter, ycenter = int(width / 2), int(height / 2)
    if n == 1:
        stars[yoff][xoff] = "*"
        return stars
    for i in range(0, xcenter + 1):
        stars[yoff + (i if n % 2 else height - i - 1)][xoff + xcenter - i] = "*"
        stars[yoff + (i if n % 2 else height - i - 1)][xoff + xcenter + i] = "*"
        stars[yoff + (height - 1 if n % 2 else 0)][xoff + xcenter - i] = "*"
        stars[yoff + (height - 1 if n % 2 else 0)][xoff + xcenter + i] = "*"
    return star(stars, n - 1, xoff + 2 ** (n - 1), yoff + (ycenter if n % 2 else 1))

width, height = (2 ** n - 1) * 2 - 1, 2 ** n - 1
stars = star([[" "] * width for _ in range(height)], n, 0, 0)
for v in map(lambda x: ''.join(x).rstrip(), stars):
    print(v)