N = int(input())
for i in range(N):
    A, B = map(int, input().split())
    s = 0
    while A:
        s += A % 2
        A >>= 1
    print(["Corrupt", "Valid"][s % 2 == B])