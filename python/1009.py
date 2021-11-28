N = int(input())
while N:
    A, B = map(int, input().split(" "))
    m = 1
    while B:
        m = (m * A) % 10
        B -= 1
    print(m if m !=0 else 10)
    N -= 1