n=int(input())
for i in range(n):
    for j in range(n):
        if j%2:print(' ',end='')
        else:print('*',end='')
    print('')
    for j in range(n):
        if j%2:print('*',end='')
        else:print(' ',end='')
    print('')
