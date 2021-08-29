n = int(input())
cnt = 0
for i in range(n - 1):
    cnt = cnt * 2 + (1 if i % 2 else -1)
print(cnt)