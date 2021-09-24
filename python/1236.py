N, M = map(int, input().split(" "))
rows = [0] * M
cols = [0] * N

for i in range(N):
    s = input()
    for j in range(M):
        if s[j] == 'X':
            rows[j], cols[i] = 1, 1

print(max(rows.count(0), cols.count(0)))