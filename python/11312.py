T = int(input())
for i in range(T):
    A, B = map(int, input().split(" "))
    print(A ** 2 // B ** 2)