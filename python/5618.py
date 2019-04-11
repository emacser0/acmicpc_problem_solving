n=int(input())
l=list(map(int,input().split()))
def gcd(a,b):
    while b!=0:
        n=a%b
        a=b
        b=n
    return a
if n==2:
    a=gcd(l[0],l[1])
else:
    a=gcd(l[2],gcd(l[0],l[1]))
for i in range(1,int(a/2+1)):
    if a%i==0:
        print(i)
print(a)
