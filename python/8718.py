x, k = map(int, input().split(" "))
if 1000 * x >= 7000 * k:
    print(7000 * k)
elif 1000 * x >= 3500 * k:
    print(3500 * k)
elif 1000 * x >= 1250 * k:
    print(1750 * k)
else:
    print(0)