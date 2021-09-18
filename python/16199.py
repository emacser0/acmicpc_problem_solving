a1, b1, c1 = map(int, input().split(" "))
a2, b2, c2 = map(int, input().split(" "))

print(a2 - a1 - (0 if b2 > b1 or (b2 == b1 and c2 >= c1) else 1))
print(a2 - a1 + 1)
print(a2 - a1)