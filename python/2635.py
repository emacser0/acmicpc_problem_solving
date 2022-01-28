N = int(input())
m = 0
ml = []
for i in range(1, 30000):
    l = [N, i]
    while 1:
        d = l[len(l) - 2] - l[len(l) - 1]
        if d < 0:
            break
        l.append(d)

    if len(l) > m:
        m = len(l)
        ml = l
print(m)
print(*ml)