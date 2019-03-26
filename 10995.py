n=int(input())
for i in range(n):
    for j in range(n*2):
        if i%2==j%2:print('*',end='')
        elif j!=n*2-1:print(' ',end='')
    print('')
