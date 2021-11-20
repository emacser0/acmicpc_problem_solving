import itertools

L = sorted(map(int, [*open(0)]))
for i, j in itertools.combinations(range(9), 2):
    s = sum(L) - L[i] - L[j]
    if s == 100:
        for k in range(9):
            if k == i or k == j:
                continue
            print(L[k])
        break
