H, W, M, N = map(int, input().split())
print((H // (M + 1) + (H % (M + 1) > 0)) * (W // (N + 1) + (W % (N + 1) > 0)))