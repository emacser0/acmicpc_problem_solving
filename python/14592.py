N = int(input())
m, mi = 0, 0
for i in range(N):
    S, C, L = map(int, input().split(" "))
    s = S * 50 * 179 - C * 179 - L
    if m < s:
        m = s
        mi = i
print(mi + 1)