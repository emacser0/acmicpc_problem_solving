import sys

sys.setrecursionlimit(100000010)

n = int(input())

tree = [[] for _ in range(n)]

for _ in range(n - 1):
    u, v = map(int, input().split(" "))
    tree[u - 1].append(v - 1)

cache = [[-1, -1] for _ in range(n)]

def dfs(i=0, ea=0):
    if len(tree[i]) == 0:
        return ea

    if cache[i][ea] >= 0:
        return cache[i][ea]

    cache[i][ea] = ea
    if ea:
        for j in tree[i]:
            a = cache[j][0] if cache[j][0] >= 0 else dfs(j, 0)
            b = cache[j][1] if cache[j][1] >= 0 else dfs(j, 1)
            cache[i][ea] += min(a, b)
    else:
        for j in tree[i]:
            cache[i][ea] += cache[j][1] if cache[j][1] >= 0 else dfs(j, 1)

    return cache[i][ea]
print(min(dfs(0, 0), dfs(0, 1)))