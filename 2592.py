c=[0 for i in range(1001)]
s=0
for i in range(10):
   n=int(input())
   c[n]+=1
   s+=n
print(int(s/10))
m=0
mi=0
for i in range(1001):
    if c[i]>m:
        m=c[i]
        mi=i
print(mi)
