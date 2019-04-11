#include <cstdio>
int n,req[10004],m,sum,left,mid,right,remained,r;
int
main() {
  scanf("%d",&n);  
  for(int i=0;i<n;i++) {
    scanf("%d",req+i);
    right=right>req[i]?right:req[i];
    sum+=req[i];
  }
  scanf("%d",&m);  
  if(sum<=m) {
    printf("%d\n",right);
    return 0;
  }
  while(left<=right) {    
    mid=(left+right)/2;    
    remained=m;
    for(int i=0;i<n;i++)
      remained-=req[i]>mid?mid:req[i];
    if(remained>=0) {
      r=mid;
      left=mid+1;
    }
    else {
      right=mid-1;
    }    
  }
  printf("%d\n",r);
}
