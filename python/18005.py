N = int(input())
if N % 2:
    print(0)
else:
    print(1 if N // 2 % 2 else 2)
