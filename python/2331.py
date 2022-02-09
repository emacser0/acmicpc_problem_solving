A, P = map(int, input().split())
l, r = [], A

while r not in l:
    l.append(r)
    r = sum(int(x) ** P for x in str(r))

print(l.index(r))