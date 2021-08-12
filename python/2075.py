import sys
input = sys.stdin.readline
n = int(input())
q = []
ql = 0

for i in range(n):
    l = list(map(int, input().split(' ')))
    for v in l:
        q.append(v)

        ci = ql
        while True:
            pi = int((ci - 1) / 2)
            if pi < 0:
                break
            if q[pi] <= q[ci]:
                break
            q[pi], q[ci] = q[ci], q[pi]

            ci = pi
            pi = int((ci - 1) / 2)
        ql += 1

        while ql > n:
            q[0] = q[ql - 1]
            ql -= 1
            ci = 0

            while True:
                left = (ci + 1) * 2 - 1
                right = (ci + 1) * 2
                if left >= ql:
                    break
                if right >= ql or q[left] < q[right]:
                    target = left
                else:
                    target = right

                if q[ci] <= q[target]:
                    break
                q[ci], q[target] = q[target], q[ci]
                ci = target

            q.pop()

print(q[0])