i = 1
while 1:
    A, B, C = map(int, input().split(" "))
    if A == B == C == 0:
        break
    elif i > 1:
        print("")

    print("Triangle #" + str(i))

    if A == -1:
        if B >= C:
            print("Impossible.")
        else:
            print("a = {:.3f}".format((C ** 2 - B ** 2) ** 0.5))
    if B == -1:
        if A >= C:
            print("Impossible.")
        else:
            print("b = {:.3f}".format((C ** 2 - A ** 2) ** 0.5))
    if C == -1:
        print("c = {:.3f}".format((A ** 2 + B ** 2) ** 0.5))

    i += 1