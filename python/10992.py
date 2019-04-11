n=int(input())
mid=n-1
for i in range(n):
    for j in range(2*n-1):
        if j==mid-i or j==mid+i:print('*',end='')
        elif j>mid-i and j<mid+i:
            if i==0 or i==n-1:print('*',end='')
            else:print(' ',end='')
        elif j<mid-i:print(' ',end='')
    print('')
