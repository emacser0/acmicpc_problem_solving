N, K = map(int, input().split())
L = list(map(int, input().split()))
m = -999999
for i in range(N - K + 1):
    m = max(sum(L[i : i + K]), m)
print(m)
