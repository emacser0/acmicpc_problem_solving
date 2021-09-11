n = int(input())

g = []

for i in range(1, 7):
    for j in range(2**i):
        gn = j
        gd = 0
        for k in range(i):
            gd += (7 if gn % 2 else 4) * 10 ** k
            gn >>= 1
        g.append(gd)

v = [0]

visited = [-1 for _ in range(1000001)]

rgn = range(len(g))

while v:
    d = v.pop(0)
    if d == n:
        break
    for i in rgn:
        if d + g[i] > n:
            break
        if visited[d + g[i]] == -1 and v.count(d + g[i]) == 0:
            v.append(d + g[i])
            visited[d + g[i]] = d

result = ""

def p(i):
    global result
    if i == 0:
        return

    p(visited[i])

    result += str(i - visited[i]) + " "

p(n)

if visited[n] >= 0:
    result.rstrip()
    print(result)
else:
    print(-1)