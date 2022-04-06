S = input()
n = len(S)

for i in range(n - 1):
    if S[i] < S[i + 1]:
        S = S[i::-1] + S[i+1:]
        S = S[i+1::-1] + S[i+2:]
print(S[::-1])