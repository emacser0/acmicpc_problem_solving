N = int(input())
L = [0] * (N + 1)
for i in range(N):
    L[int(input())] = i
print(sum([L[i + 1] < L[i] for i in range(N)]))