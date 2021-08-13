n = int(input())

l = []
maxd = 0
for i in range(n):
    d, w = map(int, input().split(" "))
    maxd = max(maxd, d)
    l.append((d, w))

schedule = [0 for i in range(1001)]
l.sort(key=lambda x: -x[1])


for i in range(n):
    for j in range(l[i][0], 0, -1):
        if schedule[j] == 0:
            schedule[j] = l[i][1]
            break

print(sum(schedule))