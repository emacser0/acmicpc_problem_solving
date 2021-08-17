import heapq

v, e = map(int, input().split(" "))
graph = [[] for _ in range(v + 1)]

pq = []
for i in range(e):
    a, b, c = map(int, input().split(" "))
    graph[a].append((c, b))
    graph[b].append((c, a))

visited = [False for _ in range(v + 1)]
heapq.heappush(pq, (0, 1))

weightsum = 0
while len(pq):
    weight, top = heapq.heappop(pq)
    if visited[top]:
        continue
    visited[top] = True
    weightsum += weight
    for edge in graph[top]:
        if not visited[edge[1]]:
            heapq.heappush(pq, edge)
print(weightsum)