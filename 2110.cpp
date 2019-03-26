#include <cstdio>
#include <cstdlib>
int n,c,x[200004];
int cmp(const void *a,const void *b) {
  int r1=*(int*)a,r2=*(int*)b;
  if(r1>r2) return 1;
  if(r1<r2) return -1;
  return 0;
}
int
main() {
  scanf("%d%d",&n,&c);
  for(int i=0;i<n;i++) {
    scanf("%d",x+i);
  }
  qsort(x,n,sizeof(int),cmp);
  int left=1,right=x[n-1]-x[0],mid,cnt,first,r;
  while(left<=right) {
    mid=(left+right)/2;
    cnt=1;
    first=x[0];
    for(int i=1;i<n;i++) {
      if(x[i]-first>=mid) {
        first=x[i];
        cnt++;
      }
    }
    if(cnt>=c) {
      left=mid+1;
      r=mid;
    }
    else {
      right=mid-1;
    }
  }
  printf("%d\n",r);
}
