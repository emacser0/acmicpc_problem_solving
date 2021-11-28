T = int(input())
while T:
    if T > 0:
        input()
    N = int(input())
    L = [int(input()) for i in range(N)]
    print("NO" if sum(L) % len(L) else "YES")
    T -= 1