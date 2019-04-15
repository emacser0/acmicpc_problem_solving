#include <stdio.h>
int T,n,max;
int
main() {
  scanf("%d",&T);
  for(int i=0;i<T;i++,max=0) {
    for(int j=0;j<5;j++) {
      scanf("%d",&n);
      max=max>n?max:n;
    }
    printf("Case #%d: %d\n",i+1,max);
  }
}
