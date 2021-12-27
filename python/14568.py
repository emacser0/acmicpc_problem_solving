N = int(input())
cnt = 0
for i in range(1, N - 1):
    for j in range(1, i - 1):
        c = N - i - j
        if c > 0 and c % 2 == 0:
            cnt += 1
print(cnt)