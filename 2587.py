s=0
l=[]
for i in range(5):
   n=int(input())
   s+=n
   l+=[n]
l.sort()
print(int(s/5))
print(l[2])
