while 1:
    a=input();b=input()
    if a[0]=='E':break;
    x,y=0,0
    for i in range(len(a)):
        if a[i]=='R':
            if b[i]=='P':y+=1
            if b[i]=='S':x+=1
        if a[i]=='P':
            if b[i]=='R':x+=1
            if b[i]=='S':y+=1
        if a[i]=='S':
            if b[i]=='R':y+=1
            if b[i]=='P':x+=1
    print("P1: {}\nP2: {}".format(x,y))
