while 1:
    L = list(map(int, input().split(" ")))
    A, L = L[0], L[1:]

    if A == 0:
        break

    cnt = 1
    for i in range(A):
        S, D = L[i * 2], L[i * 2 + 1]
        cnt = cnt * S - D
    print(cnt)