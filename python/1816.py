N = int(input())
for i in range(N):
    S = int(input())
    p = True
    for i in range(2, min(1000000, int(S ** 0.5))):
        if S % i == 0:
            p = False
            break
    print(["NO", "YES"][p])
