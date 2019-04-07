n=list(map(int,list(input())))
s=0
if len(n)>=3:
    if set(n[:2])==set([1,0]):n=n[2:];s+=10
    else:s+=n[0];n=n[1:]
    if set(n)==set([1,0]):s+=10
    else:s+=n[0]
else:
    s=n[0]+n[1]
print(s)
