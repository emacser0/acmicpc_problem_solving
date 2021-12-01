A, B = map(lambda x: int(x) - 1, input().split(" "))
print(abs(B % 4 - A % 4) + abs(B // 4 - A // 4))