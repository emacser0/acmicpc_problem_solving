import math
R, C, N = map(int, input().split(" "))
print(math.ceil(R / N) * math.ceil(C / N))