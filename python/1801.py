n = int(input())
l = list(map(int, input().split(" ")))
l.sort()

m = sum(l[0:4])
s = sum(l) + 1
marea = 0

dp = [set() for _ in range(s)]

def calc(v=0, i=0, s=0):
    dp[s].add(v)
    if i == len(l):
        return
    calc(v | 1 << i, i + 1, s + l[i])
    calc(v, i + 1, s)

calc()

dp = list(map(list, dp))
ddp = [set() for _ in range(s)]

for i in range(l[0], s // 2):
    for j in range(len(dp[i])):
        for k in range(j + 1, len(dp[i])):
            if dp[i][j] & dp[i][k] == 0:
                ddp[i].add(dp[i][j] | dp[i][k])

ddp = list(map(list, ddp))

marea = 0

def check(w, h):
    for i in range(len(ddp[w])):
        for j in range(len(ddp[h])):
            if ddp[w][i] & ddp[h][j] == 0:
                return True
    return False

for w in range(1, s):
    for h in range(w, s):
        v = w * 2 + h * 2
        if v < m or v > s or w < l[0] or h < l[0] or w * h <= marea:
            continue

        if check(w, h):
            marea = max(marea, w * h)

print(marea if marea else -1)