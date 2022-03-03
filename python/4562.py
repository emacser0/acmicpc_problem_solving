N = int(input())
for i in range(N):
    X, Y = map(int, input().split())
    print(["MMM BRAINS", "NO BRAINS"][X < Y])