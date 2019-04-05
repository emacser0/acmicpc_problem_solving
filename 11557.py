for i in range(int(input())):
    l=[];m=0;mi=0
    for j in range(int(input())):
        s=input().split()
        l+=[s[0]]
        if int(s[1])>m:m=int(s[1]);mi=j
    print(l[mi])
