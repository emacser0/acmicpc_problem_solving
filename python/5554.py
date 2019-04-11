s,m=0,0
for i in range(4):
    s+=int(input())
while s>=60:
    s-=60
    m+=1
print(m)
print(s)
