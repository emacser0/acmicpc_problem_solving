L = int(input())
S = sorted(list(map(int, input().split(" "))))
N = int(input())

index = 0
while index < len(S) and S[index] < N:
    index += 1

cnt = 0
start = S[index - 1] if index else 0
for i in range(start + 1, N + 1):
    for j in range(N if i < N else N + 1, S[index]):
        cnt += 1
print(cnt)