n = int(input())
tree = [[] for _ in range(n + 1)]
tree[1] = [(0, 0), (0, 0)]
for _ in range(n - 1):
    a, b = map(int, input().split(" "))
    tree[a]