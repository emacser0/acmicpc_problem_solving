T = int(input())
for i in range(T):
    n = int(input())
    for j in range(n):
        if j > 0 and j < n - 1:
            print("#" + "J" * (n - 2) +"#")
        else:
            print("#" * n)
    if i < T - 1:
        print("")