A, B, C = map(int, input().split())
print(["*", "A", "B", "C"][(A != B == C) + (B != C == A) * 2 + (C != A == B) * 3])
