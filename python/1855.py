K = int(input())
S = input()

n = len(S)

for i in range(K):
    for j in range(n // K):
        if j % 2:
            print(S[j * K + K - i - 1], end='')
        else:
            print(S[j * K + i], end='')
print("")