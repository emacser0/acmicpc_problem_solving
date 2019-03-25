a=int(input())
b=int(input())
l=list(map(int,str(b)))
l.reverse()
for i in l:
    print(a*i)
print(a*b)
