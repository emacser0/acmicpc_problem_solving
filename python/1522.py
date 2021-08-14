s = list(input())
n = len(s)

windows = []
window_size = s.count('a')

for i in range(n):
    windows.append([])
    for j in range(window_size):
        windows[i].append((i + j) % n)

result = n
for window in windows:
    bcnt = 0
    for i in window:
        if s[i] == 'b':
            bcnt += 1
    result = min(result, bcnt)

print(result)