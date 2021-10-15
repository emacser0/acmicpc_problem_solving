N, K = map(int, input().split(" "))

D = len(str(N))
n = N % K
d = n
i = 1

cnt = set()
while i <= K:
    if n == 0:
        break
    cnt.add(n)
    d = (d * (10 ** D) % K) % K
    n = (n + d) % K
    i += 1
print(i if i <= K else -1)
