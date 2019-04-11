h,m=map(int,input().split())
if m<45:
    h-=1
    if h==-1:h=23
m=(m-45)%60
print(h,m)
