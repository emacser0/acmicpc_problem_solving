n, m = map(int, input().split(" "))

indegrees = [0 for _ in range(n)]
graph = [[] for _ in range(n)]
for _ in range(m):
    k, *l = map(int, input().split(" "))
    for i in range(0, k - 1):
        graph[l[i] - 1].append(l[i + 1] - 1)
        indegrees[l[i + 1] - 1] += 1

queue = []
for i in range(n):
    if indegrees[i] == 0:
        queue.append(i)

result = []
while len(queue):
    p = queue.pop(0)
    result.append(p + 1)
    for x in graph[p]:
        indegrees[x] -= 1
        if indegrees[x] == 0:
            queue.append(x)
if len(result) == n:
    for v in result:
        print(v)
else:
    print(0)