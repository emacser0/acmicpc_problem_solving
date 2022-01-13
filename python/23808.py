N = int(input())
for i in range(2 * N):
    for j in range(5 * N):
        print([" ", "@"][j // N in [0, 4]], end='')
    print("")
for i in range(N):
    print("@" * 5 * N)
for i in range(N):
    for j in range(5 * N):
        print([" ", "@"][j // N in [0, 4]], end='')
    print("")
for i in range(N):
    print("@" * 5 * N)