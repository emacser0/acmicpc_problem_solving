#include <stdio.h>
int n;
int
main() {
  scanf("%d",&n);
  for(int i=2;i<=n;i++) {
    if(n==1)break;
    while(n%i==0) {
      n/=i;
      printf("%d\n",i);
    }
  }
}
