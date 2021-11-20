import math
X, Y = map(int, input().split(" "))
print(math.ceil(X / (Y - X)) + 1)