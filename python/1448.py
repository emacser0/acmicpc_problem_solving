N = int(input())
L = sorted([int(input()) for i in range(N)], reverse=True)

def find(n, l):
    for i in range(n - 2):
        if l[i] < l[i + 1] + l[i + 2]:
            return sum(l[i:i+3])
    return -1
print(find(N, L))