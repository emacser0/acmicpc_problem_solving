L = list(map(int, input().split(" ")))
if sum(L) >= 100:
    print("OK")
else:
    m = L[0]
    mi = 0
    if L[1] < m:
        m = L[1]
        mi = 1
    if L[2] < m:
        mi = 2
    print(["Soongsil", "Korea", "Hanyang"][mi])