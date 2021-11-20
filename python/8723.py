A, B, C = sorted(map(int, input().split(" ")))
print(2 if A == B == C else (1 if A * A + B * B == C * C else 0))