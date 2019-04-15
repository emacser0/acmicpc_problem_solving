#include <stdio.h>
int a,b;
int
main() {
  while(scanf("%d%d",&a,&b),a+b) {
    printf("%d %d / %d\n",a/b,a%b,b);
  }
}
