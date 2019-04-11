n=int(input())
l=list(map(int,input().split()))
r=[0 for x in range(n)]
for i in range(n):
    for j in range(n):
        if not r[j] and not l[i]:
            r[j]=i+1
            break
        if not r[j]:
            l[i]-=1
print(' '.join(str(i) for i in r))
