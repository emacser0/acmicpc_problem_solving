N = int(input())
L = list(map(int, input().split(" ")))
a = sum(map(lambda x: (x // 30 + 1) * 10, L))
b = sum(map(lambda x: (x // 60 + 1) * 15, L))
if a < b:
    print("Y", a)
elif a == b:
    print("Y M", a)
else:
    print("M", b)