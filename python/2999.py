S = input()
n = len(S)
R, C = 0, 0
for i in range(1, n // 2 + 1):
    if n % i:
        continue
    if i > n // i:
        continue
    C = i
    R = n // i
for i in range(C):
    for j in range(R):
        print(S[j * C + i], end='')
print("")