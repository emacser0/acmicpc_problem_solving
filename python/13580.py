A, B, C = sorted(map(int, input().split(" ")))
print("S" if A + B == C or B == C or A == B else "N")