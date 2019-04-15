#include <stdio.h>
int T,n,s,min=2e9;
int
main() {
  scanf("%d",&T);
  for(int i=0;i<T;i++,s=0,min=2e9) {
    for(int j=0;j<7;j++) {
      scanf("%d",&n);
      if(n%2==0){s+=n;min=min<n?min:n;}
    }
    printf("%d %d\n",s,min);
  }
}
