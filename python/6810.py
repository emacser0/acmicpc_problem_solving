L = [9, 7, 8, 0, 9, 2, 1, 4, 1, 8] + list(map(int, [*open(0)]))
print("The 1-3-sum is", sum([[1, 3][i % 2] * L[i] for i in range(len(L))]))