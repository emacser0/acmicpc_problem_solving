n=int(input())
m=int(input())
if m:d=list(map(int,input().split()))
else:d=[]
m=abs(n-100)
c = [0 for i in range(10)]
for i in d:
    c[i]=1
def J(a,b,s=1):
    for i in range(a,b,s):
        nl=map(int,str(i))
        x=1
        for j in nl:
            if c[j]==1:
                x=0
                break
        if x:
            return i           
    return -1
on1=J(n,max(n-m,0)-1,-1)
s1=n-on1
on2=J(n,n+m+1)
s2=on2-n
r=[]
if on1!=-1:
    r+=[s1+len(str(on1))]
if on2!=-1:
    r+=[s2+len(str(on2))]
r+=[m]
print(min(r))
