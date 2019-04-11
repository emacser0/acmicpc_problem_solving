a,b,c=map(int,input().split())
c+=int(input())
while c>=60:
    b+=1
    c-=60
while b>=60:
    a+=1
    b-=60
    if a==24:a=0
print(a,b,c)
