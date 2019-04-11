l=[]
for i in range(int(input())):
    l+=[int(input())]
print('\n'.join(str(x) for x in sorted(l,reverse=True)))
