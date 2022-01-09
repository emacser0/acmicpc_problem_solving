N = int(input())
for i in range(N):
    for j in range(5 * N):
        print(["@", " "][j // N == 3], end='')
    print("")
for i in range(3 * N):
    for j in range(5 * N):
        print(["@", " "][j // N in [1, 3]], end='')
    print("")
for i in range(N):
    for j in range(5 * N):
        print(["@", " "][j // N == 1], end='')
    print("")
