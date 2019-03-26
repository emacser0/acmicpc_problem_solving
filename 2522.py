n=int(input())
for i in range(n):
    for j in range(n):
        if j>=n-i-1:print('*',end='')
        else:print(' ',end='')
    print('')
for i in range(n-2,-1,-1):
    for j in range(n):
        if j>=n-i-1:print('*',end='')
        else:print(' ',end='')
    print('')
