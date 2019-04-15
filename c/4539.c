#include <stdio.h>
int n,x,m;
int
main() {
  scanf("%d",&n);
  for(int i=0;i<n;i++) {
    scanf("%d",&x);
    for(m=10;x/m;m*=10) {
      if(x%m>4*(m/10)) x=(x/m+1)*m;
      else x=(x/m)*m;
    }
    printf("%d\n",x);
  }
}
