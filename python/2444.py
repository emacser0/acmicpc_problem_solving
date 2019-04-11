n=int(input())
mid=n-1
for i in range(n-1):
    for j in range(2*n-1):
        if j>=mid-i and j<=mid+i:print('*',end='')
        elif j<mid-i:print(' ',end='')
    print('')
for i in range(n):
    for j in range(2*n-1):
        if j>=mid-(n-i-1) and j<=mid+(n-i-1):print('*',end='')
        elif j<mid-(n-i-1):print(' ',end='')
    print('')
