n=int(input())
a=list(map(int,input().split()))
def calc(l):
    s=0
    for i in range(len(l)-1):
        s+=abs(l[i]-l[i+1])
    return s
m=0
def rec(o,l):
    global n,m
    if len(l)==n:
        r=calc(l)
        m=m if m>r else r
    else:
        for i in o:
            d=o.copy()
            d.remove(i)
            rec(d,l+[i])
rec(a,[])
print(m)
