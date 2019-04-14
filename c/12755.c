#include <stdio.h>
int n,t,stack[20],si;
int
main() {
  scanf("%d",&n);
  for(int i=1;n;i++) {
    t=i;
    for(;t;t/=10) {
      stack[si++]=t%10;
    }
    for(;si;si--) {
      n--;
      if(!n) {
        printf("%d\n",stack[si-1]);
        break;
      }
    }
  }
}
