l=[int(input()) for _ in range(int(input()))]
r=l[len(l)-1]
if l[1]-l[0]==l[2]-l[1]:print(r+l[1]-l[0])
else:print(int(r*l[1]/l[0]))
