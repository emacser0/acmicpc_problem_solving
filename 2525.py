a,b=map(int,input().split())
b+=int(input())
while b>=60:
    a+=1
    b-=60
    if a==24:a=0
print(a,b)
