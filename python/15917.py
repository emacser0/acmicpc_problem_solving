import sys
N = int(input())
for i in range(N):
    print(int(bin(int(sys.stdin.readline().strip())).count('1') == 1))