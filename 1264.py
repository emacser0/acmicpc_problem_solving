l=['a','A','e','E','i','I','o','O','u','U']
while 1:
    s=input()
    if s=="#":
        break
    c=0
    for i in s:
        for j in l:
            if i==j:
                c+=1
                break
    print(c)
