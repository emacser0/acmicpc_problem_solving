n = int(input())
table = []
for i in range(n):
    table.append(list(map(int, input().split(" "))))

mc = 0
mi = 0
for i in range(n):
    cnt = [0 for _ in range(n)]
    for j in range(5):
        for k in range(n):
            if table[i][j] == table[k][j]:
                cnt[k] = 1

    v = sum(cnt)
    if v > mc:
        mc = v
        mi = i

print(mi + 1)