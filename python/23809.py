N = int(input())
for i in range(2):
    for j in range(N):
        print("@" * N + " " * (3 - i) * N + "@" * N)
for i in range(N):
    print("@" * 3 * N)
for i in range(2):
    for j in range(N):
        print("@" * N + " " * (2 + i) * N + "@" * N)
