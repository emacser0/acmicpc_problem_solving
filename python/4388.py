while 1:
    A, B = map(int, input().split(" "))
    if A == B == 0:
        break

    carry = 0
    pc = 0
    while A or B:
        c = max(A % 10 + B % 10 + pc - 9, 0)
        A //= 10
        B //= 10

        carry += c > 0
        pc = c

    print(carry)
