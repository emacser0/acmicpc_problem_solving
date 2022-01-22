N = int(input())
s = 0
for i in range(1, N - 1):
    s += i * (N - 1 - i)
print(str(s) + "\n3")