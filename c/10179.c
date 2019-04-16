#include <stdio.h>
#include <math.h>
int n;
double d;
int
main() {
  scanf("%d",&n);
  for(int i=0;i<n;i++) {
    scanf("%lf",&d);
    printf("$%.2f\n",d*0.8);
  }
}
