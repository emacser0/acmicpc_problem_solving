m = int(input())
s = list(map(lambda x: ord(x) - ord('A'), input()))
n = len(s)

min_cnt = 10 ** 99

for i in range(1, m + 1):
    c = [[0] * 26 for _ in range(i)]
    for j in range(0, n):
        c[j % i][s[j]] += 1
    cnt = sum([sum(d) - max(d) if d.count(0) < 25 else 0 for d in c])
    min_cnt = min(min_cnt, cnt)

print(min_cnt)