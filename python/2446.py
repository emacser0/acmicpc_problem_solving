n=int(input())
mid=n-1
def draw(a,b,c):
    global n,mid
    for i in range(a,b,c):
        for j in range(2*n-1):
            if j>=mid-i and j<=mid+i:print('*',end='')
            elif j<mid-i:print(' ',end='')
        print('')
draw(n-1,0,-1)
draw(0,n,1)
