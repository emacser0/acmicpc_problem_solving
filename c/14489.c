#include <stdio.h>
int a,b,c;
int
main() {
  scanf("%d%d%d",&a,&b,&c);
  printf("%d\n",a+b<c*2?a+b:a+b-c*2);
}
