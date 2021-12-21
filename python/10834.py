M = int(input())
speed = 1
ccw = 0
for i in range(M):
    A, B, C = map(int, input().split(" "))
    speed = speed * B / A
    if C == 1:
        ccw = not ccw

print(int(ccw), int(speed))