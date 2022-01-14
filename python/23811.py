N = int(input())
for i in range(5):
    for j in range(N):
        print(["@" * 5 * N, "@" * N][i % 2])