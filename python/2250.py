import math
N = int(input())
D = int(math.log2(N + 0.5)) + 2
tree = [[0, 0]] * (N + 1)

for i in range(N):
    a, b, c = map(int, input().split(" "))
    tree[a] = [b, c]

root = 1
visited = [0] * (N + 1)
for i in range(1, N + 1):
    if tree[i][0] > 0:
        visited[tree[i][0]] = 1
    if tree[i][1] > 0:
        visited[tree[i][1]] = 1

for i in range(1, N + 1):
    if visited[i] == 0:
        root = i

rows = [[0, 0]] * (N + 1)
row_index = 0
lr = [[9e9, -1] for _ in range(1000)]

def dfs(i, d):
    global rows, row_index, lr
    if tree[i][0] > 0:
        dfs(tree[i][0], d + 1)

    rows[row_index] = [tree[i], d]
    lr[d][0] = min(lr[d][0], row_index)
    lr[d][1] = max(lr[d][1], row_index)
    row_index += 1

    if tree[i][1] > 0:
        dfs(tree[i][1], d + 1)

dfs(root, 0)

max_width = 0
max_level = 0
for i in range(D):
    if lr[i][1] - lr[i][0] + 1 > max_width:
        max_width = lr[i][1] - lr[i][0] + 1
        max_level = i
print(max_level + 1, max_width)

