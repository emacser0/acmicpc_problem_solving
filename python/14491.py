T = int(input())
s = ""
while T:
    s = str(T % 9) + s
    T //= 9
print(s)
