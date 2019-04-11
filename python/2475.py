from functools import reduce
l=list(map(int,input().split()))
print(reduce(lambda x,y:x+y**2,l,0)%10)
