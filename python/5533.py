n=int(input())
a=[[] for x in range(n)]
for i in range(n):
    a[i]=list(map(int,input().split()))+[0]
for i in range(3):
    c=[0 for x in range(101)]
    for j in a:
        c[j[i]]+=1
    for j in a:
        if c[j[i]]==1:
            j[3]+=j[i]
for i in a:
    print(i[3])
