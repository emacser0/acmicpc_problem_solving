N = int(input())
L = []
for _ in range(N):
    L.append(input()[::-1])

for i in range(len(L[0])):
    d = {}
    for j in range(N):
        s = L[j][:i+1]
        d[s] = d[s] + 1 if s in d else 1

    if max(d.values()) <= 1:
        print(i + 1)
        break