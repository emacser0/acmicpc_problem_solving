A, D, K = map(int,input().split())
i = abs((K - A) // D)
print(["X", i + 1][A + D * i == K])