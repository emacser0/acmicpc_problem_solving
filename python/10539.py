n=int(input())
b=list(map(int,input().split()))
a=[]
for i in range(n):
    a+=[b[i]*(i+1)-sum(a)]
print(' '.join(str(x) for x in a))
