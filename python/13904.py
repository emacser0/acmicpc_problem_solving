n = int(input())

l = []
maxd = 0
for i in range(n):
    d, w = map(int, input().split(" "))
    maxd = max(maxd, d)
    l.append((d, w))

l1 = list(l)
l1.sort(key=lambda x: x[0])
l1.sort(key=lambda x: -x[1])
tw1 = 0
for t in range(maxd + 1):
    if not len(l1):
        break
    l1 = list(filter(lambda x: x[0] - t > 0, l1))

    tw1 += l1[0][1]
    l1.pop(0)

print(tw1)
