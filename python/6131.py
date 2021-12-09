N = int(input())

cnt = 0
for i in range(1, 501):
    for j in range(i + 1, 501):
       if i ** 2 + N == j ** 2:
           cnt += 1

print(cnt)