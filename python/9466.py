import sys
sys.setrecursionlimit(120000)

T = int(input())

def dfs(n):
    global s
    visited[n] = True
    if not visited[l[n]]:
        dfs(l[n])
    elif not done[l[n]]:
        next = l[n]
        while next != n:
            s += 1
            next = l[next]
        s += 1
    done[n] = True

for _ in range(T):
    n = int(input())
    l = [0] + list(map(int, input().split(" ")))

    r = range(n + 1)

    done = [False for _ in r]
    visited = [False for _ in r]
    s = 0
    for i in range(1, n + 1):
        if not visited[i]:
            dfs(i)
    print(n - s)