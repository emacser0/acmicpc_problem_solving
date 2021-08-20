import heapq, math

n = int(input())

stars = []

for _ in range(n):
    x, y = map(float, input().split(" "))
    stars.append((x, y))

def get_squared_distance(a, b):
    return (stars[a][0] - stars[b][0]) ** 2 + (stars[a][1] - stars[b][1]) ** 2

def get_distance(a, b):
    return math.sqrt(get_squared_distance(a, b))

pq = [(0, 0)]
visited = [False for _ in range(n)]

distancesum = 0
while len(pq):
    distance, v = heapq.heappop(pq)
    if visited[v]:
        continue
    distancesum += distance
    visited[v] = True
    for i in range(n):
        if visited[i]:
            continue
        sd = get_distance(v, i)
        heapq.heappush(pq, (sd, i))

print("{:.2f}".format(distancesum))