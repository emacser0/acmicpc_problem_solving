#include <stdio.h>
int n,s;
int
main() {
  for(;scanf("%d",&n),n;) {
    s=1;
    while(n) {
      s+=n%10==0?5:n%10==1?3:4;
      n/=10;
    }
    printf("%d\n",s);
  }
}
