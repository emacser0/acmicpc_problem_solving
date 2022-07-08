A, B = eval('list(map(int, input().split(":"))),' * 2)
a = A[0] * 3600 + A[1] * 60 + A[2]
b = B[0] * 3600 + B[1] * 60 + B[2]
if b <= a:
    b += 86400
c = b - a
print("{:02d}:{:02d}:{:02d}".format(c // 3600, (c % 3600) // 60, (c % 3600) % 60))