n=int(input())
m=[]
for i in range(n):
    m+=[[x for x in input()]]
a,b=0,0
for i in range(n):
    c=0
    for j in range(n):
        if m[i][j]=='.':c+=1
        else:
            if c>1:a+=1
            c=0
    if c>1:a+=1
for i in range(n):
    c=0
    for j in range(n):
        if m[j][i]!='X':c+=1
        else:
            if c>1:b+=1
            c=0
    if c>1:b+=1
print(a,b)
