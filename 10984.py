t=int(input())
for i in range(t):
    n=int(input())
    ca,a=0,0
    for j in range(n):
        m=input().split()
        c=int(m[0])
        g=float(m[1])
        ca+=c
        a+=c*g
    print(ca,a/ca)
