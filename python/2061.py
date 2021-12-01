K, L = map(int, input().split(" "))
m = 0
for i in range(2, L):
    if K % i == 0:
        m = i
        break

if m == 0:
    print("GOOD")
else:
    print("BAD", m)
