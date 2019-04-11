n=input()
if len(n)>1 and n[1]=='x':
    print(int(n,16))
elif n[0]=='0':
    print(int(n,8))
else:
    print(n)
