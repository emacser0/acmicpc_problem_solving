for s in open(0):
    A, B, C = map(int, s.split(" "))
    print(max(B - A - 1, C - B - 1))