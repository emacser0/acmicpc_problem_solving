A, B, C, D = map(int, input().split(" "))
P, M, N = map(int, input().split(" "))

print(((P - 1) % (A + B) < A) + ((P - 1) % (C + D) < C))
print(((M - 1) % (A + B) < A) + ((M - 1) % (C + D) < C))
print(((N - 1) % (A + B) < A) + ((N - 1) % (C + D) < C))