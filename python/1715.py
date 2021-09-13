n = int(input())
l = []
for i in range(n):
    l.append(int(input()))
l.sort()
s = 0

for i in range(1, n):
    l[i] = l[i] + l[i - 1]
    s += l[i]
    l.sort()

print(s)