l=['-','\\','(','@','?','>','&','%','/']
while 1:
    m,c=1,0
    s=list(input())
    s.reverse()
    if s[0]=='#':break
    for i in s:
        for j in range(8):
            if i==l[j]:c+=m*j;break;
        if i==l[8]:c-=m
        m*=8
    print(c)
