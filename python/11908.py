N = int(input())
L = sorted(map(int, input().split(" ")))
print(sum(L) - L[-1])
