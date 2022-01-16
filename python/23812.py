N = int(input())
for i in range(5):
    for j in range(N):
        for k in range(5):
            print(("@" if i % 2 else [" ", "@"][k in [0, 4]]) * N, end='')
        print("")