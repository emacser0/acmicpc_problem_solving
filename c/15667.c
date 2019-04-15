#include <stdio.h>
#include <math.h>
int n;
int
main() {
  scanf("%d",&n);
  printf("%d\n",(-1+(int)sqrt(4*n-3))/2);
}
