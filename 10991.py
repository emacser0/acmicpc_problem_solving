n=int(input())
mid=n-1
for i in range(n):
    for j in range(2*n-1):
        if j>=mid-i and j<=mid+i and (n-i)%2!=j%2:print('*',end='')
        elif j<mid-i or (j>mid-i and j<mid+i) and (n-i)%2==j%2:print(' ',end='')
    print('')
