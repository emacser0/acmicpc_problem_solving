g = 1
while 1:
    N = int(input())

    if N == 0:
        break

    if g > 1:
        print("")

    p = [["P"] * (N - 1) for i in range(N)]
    n = []
    for i in range(N):
        L = input().split(" ")
        n.append(L[0])
        L = L[1:]

        for j in range(N - 1):
            p[i][j] = [0, 1][L[j] == "N"]


    nasty = False

    print("Group", g)

    for i in range(N):
        for j in range(N - 1):
            if p[i][j]:
                index = (N + i - j - 1) % N
                print(n[index] + " was nasty about " + n[i])
                nasty = True

    if not nasty:
        print("Nobody was nasty")

    g += 1