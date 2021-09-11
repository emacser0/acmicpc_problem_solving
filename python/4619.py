while 1:
    b, n = map(int, input().split(" "))
    if b == n == 0:
        break
    min_d = 10**99
    min_i = 0
    for i in range(1, b + 1):
        v = i ** n
        if min_d > abs(v - b):
            min_d = abs(v - b)
            min_i = i
        if v > b:
            break
    print(min_i)
