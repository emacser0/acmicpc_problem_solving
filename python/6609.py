for l in open(0):
    M, P, L, E, R, S, N = map(int, l.split(" "))
    for i in range(N):
        e = M * E
        M = P // S
        P = L // R
        L = e
    print(M)