#include <stdio.h>
#include <math.h>
int T,d;
int
main() {
  scanf("%d",&T);
  for(int i=0;i<T;i++) {
    scanf("%d",&d);
    printf("%d\n",(int)((-1+sqrt(1+4*d))/2));
  }
}
