#include <stdio.h>
int c,k,p;
int
main() {
  scanf("%d%d%d",&c,&k,&p);
  printf("%d\n",(k*c*(c+1))/2+(p*c*(c+1)*(2*c+1))/6);
}
