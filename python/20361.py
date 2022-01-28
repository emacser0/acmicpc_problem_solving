N, X, K = map(int, input().split())
for i in range(K):
    A, B = map(int, input().split())
    if X == A:
        X = B
    elif X == B:
        X = A
print(X)
