X, Y = map(int, input().split(" "))
m = X / Y * 1000
for i in range(int(input())):
    X, Y = map(int, input().split(" "))
    m = min(m, X / Y * 1000)
print("{:.2f}".format(m))
