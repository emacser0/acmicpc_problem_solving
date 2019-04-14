#include <stdio.h>
int T,a,b,r;
int gcd(int x,int y) {
  int t;
  while(y!=0) {
    t=x%y;
    x=y;
    y=t;
  }
  return x;
}
int
main() {
  scanf("%d",&T);
  for(int i=0;i<T;i++) {
    scanf("%d%d",&a,&b);
    r=a>b?gcd(a,b):gcd(b,a);
    printf("%d %d\n",(a*b)/r,r);
  }
}
