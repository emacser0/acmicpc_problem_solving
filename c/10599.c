#include <stdio.h>
int a,b,c,d;
int
main() {
  while(scanf("%d%d%d%d",&a,&b,&c,&d),a+b+c+d) {
    printf("%d %d\n",c-b,d-a);
  }
}
