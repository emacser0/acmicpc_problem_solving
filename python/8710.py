import math
K, W, M = map(int, input().split(" "))
print(math.ceil((W - K) / M))
