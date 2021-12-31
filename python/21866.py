L = list(map(int, input().split(" ")))
if sum([L[i - 2] > (100 * (i // 2)) for i in range(2, 11)]):
    print("hacker")
elif sum(L) >= 100:
    print("draw")
else:
    print("none")