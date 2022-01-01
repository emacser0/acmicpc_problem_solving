N, K = map(int, input().split(" "))
l = [i for i in range(1, N + 1)]
l = list(filter(lambda x : x % 10 != K % 10 and x % 10 != (K * 2) % 10, l))
print(len(l))
print(*l)
