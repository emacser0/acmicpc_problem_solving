#include <stdio.h>
int n,o,d,t,r;
int gcd(int x,int y) {
  while(y!=0) {
    t=x%y;
    x=y;
    y=t;
  }
  return x;
}
int
main() {
  scanf("%d",&n);
  scanf("%d",&o);
  for(int i=0;i<n-1;i++) {
    scanf("%d",&d);
    r=gcd(o,d);
    printf("%d/%d\n",o/r,d/r);
  }
}
