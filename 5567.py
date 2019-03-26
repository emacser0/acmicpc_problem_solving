n = int(input())
m = int(input())
l=n+1
adj = [[0]*l for x in range(0,l)]
visited = [0]*l
for i in range(0,m):
    a, b = map(int,input().split())
    adj[a][b], adj[b][a] = 1,1
queue, cnt = [i for i in range(2,l) if adj[1][i]], 0
for i in queue:
    visited[i] = 1
    for j in range(2,l):
        if adj[i][j] and not visited[j]:
            visited[j]=1
print(len(list(filter(lambda x: x,visited))))
