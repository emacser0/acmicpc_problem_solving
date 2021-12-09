i = 1
while 1:
    A, B, C = map(float, input().split(" "))
    if B == 0:
        break
    d = A * 3.1415927 * B / 5280 / 12

    print("Trip #{}: {:.2f} {:.2f}".format(i, d, d / C * 3600))
    i += 1
