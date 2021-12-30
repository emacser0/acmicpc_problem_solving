A, B, C = sorted(map(int, input().split(" ")))
print(A + B + min(C, A + B - 1))