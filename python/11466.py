A, B = sorted(map(int, input().split(" ")))
print(max(min(A / 3, B), min(B / 3, A), A / 2))