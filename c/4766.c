#include <stdio.h>
float n,p;
int
main() {
  scanf("%f",&p);
  while(1) {
    scanf("%f",&n);
    if(n==999)break;
    printf("%.2f\n",n-p);
    p=n;
  }
}
