L, R = map(int, input().split(" "))
m = max(L, R)
if m > 0:
    print(["Odd", "Even"][L == R], m * 2)
else:
    print("Not a moose")
