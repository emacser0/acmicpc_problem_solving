D, H, M = map(int, input().split(" "))
R = D * 1440 + H * 60 + M - 16511
print(R if R >= 0 else -1)