A, B = eval('list(map(int, input().split(" "))),' * 2)
a, b, d, ai, bi = 0, 0, 0, -1, -1
for i in range(10):
    if A[i] > B[i]:
        a += 3
        ai = i
    elif A[i] < B[i]:
        b += 3
        bi = i
    else:
        d += 1
print(a + d, b + d)
print("A" if a > b else ("B" if a < b else ("A" if ai > bi else ("B" if ai < bi else "D"))))