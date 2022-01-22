N = int(input())
s, r = 0, 0
for i in list(map(int, input().split(" "))):
    if s == i:
        r += 1
        s = (s + 1) % 3
print(r)