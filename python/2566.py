m,mr,mc=0,0,0
for i in range(9):
    l=list(map(int,input().split()))
    for j in range(9):
        if l[j]>m:
            m=l[j]
            mr=i
            mc=j
print(m)
print(mr+1,mc+1)
