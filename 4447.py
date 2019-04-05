for i in range(int(input())):
    s=[x for x in input()]
    g,b=0,0
    for i in s:
        if i=='g' or i=='G':g+=1
        if i=='b' or i=='B':b+=1
    print(''.join(s) + " is " + ("GOOD" if g>b else "A BADDY" if g<b else "NEUTRAL"))
