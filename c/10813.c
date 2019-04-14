#include <stdio.h>
int a[104],n,m,x,y,t;
#define swap(a,b) t=a;a=b;b=t
int
main() {
  for(int i=1;i<101;i++) {
    a[i]=i;
  }
  scanf("%d%d",&n,&m);
  for(int i=0;i<m;i++) {
    scanf("%d%d",&x,&y);
    swap(a[x],a[y]);
  }
  for(int i=1;i<n+1;i++) {
    printf("%d ",a[i]);
  }
  puts("");
}
