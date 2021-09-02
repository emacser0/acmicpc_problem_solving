n = int(input())
l = list(map(int, input().split(" ")))
l.sort()
ll = len(l)
m = l[0] + l[1] + l[2] + l[3]
s = sum(l)
max_area = 0

def check(p, visited=0, t=0, i=0, s=0):
    if s == t:
        p.append(visited)
        return
    if s > t or i == ll:
        return
    if visited & (1 << i) == 0:
        visited |= 1 << i
        a = check(p, visited, t, i + 1, s + l[i])
        visited -= 1 << i
    check(p, visited, t, i + 1, s)

def compare(a, b):
    while a > 0 and b > 0:
        if a % 2 == b % 2 == 1:
            return False
        a >>= 1
        b >>= 1
    return True

for w in range(1, 100):
    for h in range(1, 100):
        v = w * 2 + h * 2
        if v < m or v > s:
            continue
        if w * 4 > s or h * 4 > s:
            continue
        if w < l[0] or h < l[0]:
            continue
        if w * h <= max_area:
            continue

        wp, hp = [], []

        check(wp, 0, w)
        check(hp, 0, h)

        wwp, hhp = [], []

        wpl = len(wp)
        hpl = len(hp)
        for i in range(wpl):
            for j in range(wpl):
                if compare(wp[i], wp[j]):
                    wwp.append(wp[i] | wp[j])

        for i in range(hpl):
            for j in range(hpl):
                if compare(hp[i], hp[j]):
                    hhp.append(hp[i] | hp[j])

        wp, hp = [], []
        exists = False
        for i in range(len(wwp)):
            for j in range(len(hhp)):
                if compare(wwp[i], hhp[j]):
                    exists = True
                    break
        if exists:
            max_area = max(max_area, w * h)

print(max_area)