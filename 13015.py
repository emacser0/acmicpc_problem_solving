n=int(input())
r=2*n-1
l=4*(n-1)+1
for x in range(r):
    i=r-1-x if x>n-1 else x
    for j in range(l):
        if i==0:
            if (j>i-1 and j<n+i) or (j>l-i-n-1 and j<l-i):print('*',end='')
            else:print(' ',end='')
        elif j==i or j==n+i-1 or j==l-i-1 or j==l-i-n:print('*',end='')
        elif j<l-i:print(' ',end='')
    print('')
