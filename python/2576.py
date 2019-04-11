l=[]
for i in range(7):
    l+=[int(input())]
l=[x for x in l if x%2!=0]
l.sort()
if len(l)!=0:print("{}\n{}".format(sum(l),l[0]))
else:print(-1)
