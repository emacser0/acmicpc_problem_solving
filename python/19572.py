l = list(map(int, input().split()))
l = list(map(lambda x: sum(l) / 2 - x, l))
print([-1, "1\n{} {} {}".format(*l[::-1])][min(l) > 0])