T = int(input())
print(len(list(filter(lambda x: x == T, map(int, input().split(" "))))))