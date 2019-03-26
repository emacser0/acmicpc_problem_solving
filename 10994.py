n=int(input())
mid=2*(n-1)
len=4*(n-1)+1
l=[[" "]*len for x in range(len)]
for i in range(n):
 for j in range(mid-2*i,mid+2*i+1):
  l[mid-2*i][j],l[mid+2*i][j],l[j][mid-2*i],l[j][mid+2*i]="*","*","*","*"
for i in l:print(''.join(i))
