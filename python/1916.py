import heapq

N, M = eval('int(input()),'*2)

graph = [[9e9] * (N + 1) for _ in range(N + 1)]
dist = [9e9] * (N + 1)

for _ in range(M):
    a, b, c = map(int, input().split(" "))
    graph[a][b] = min(graph[a][b], c)

A, B = map(int, input().split(" "))
dist[A] = 0

heap = [(0, A)]

while heap:
    c, i = heapq.heappop(heap)
    for j in range(1, N + 1):
        if dist[j] > dist[i] + graph[i][j]:
            dist[j] = dist[i] + graph[i][j]
            heapq.heappush(heap, (dist[i] + graph[i][j], j))

print(dist[B])