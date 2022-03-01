L, R, A = map(int, input().split())
L, R = min(L, R), max(L, R)
if L == R:
    print(L + R + A - A % 2)
elif R - L - A > 0:
    print((L + A) * 2)
else:
    print(R * 2 + (L + A - R) // 2 * 2)