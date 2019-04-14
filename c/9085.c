#include <stdio.h>
int T,n,t,s;
int
main() {
  scanf("%d",&T);
  for(int i=0;i<T;i++) {
    scanf("%d",&n);
    s=0;
    for(int j=0;j<n;j++) {
      scanf("%d",&t);
      s+=t;
    }
    printf("%d\n",s);
  }
}
