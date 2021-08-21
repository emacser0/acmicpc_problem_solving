import heapq
INPUT = lambda:map(int, input().split(" "))
n, m = INPUT()

graph = [[] for _ in range(n + 1)]
for i in range(m):
    a, b, c = INPUT()
    graph[a].append((c, b))
    graph[b].append((c, a))

visited = [False for _ in range(n + 1)]

pq = [(0, 1)]
s = 0
maxweight = 0

while len(pq):
    weight, number = heapq.heappop(pq)
    if visited[number]:
        continue
    s += weight
    maxweight = max(maxweight, weight)
    visited[number] = True
    for edge in graph[number]:
        if visited[edge[1]]:
            continue
        heapq.heappush(pq, edge)

print(s - maxweight)
