#include <stdio.h>
long long a,b,c,d,t;
int
main() {
  scanf("%d%d%d%d",&a,&b,&c,&d);
  t=b;
  while(t)t/=10,a*=10;
  t=d;
  while(t)t/=10,c*=10;
  printf("%lld\n",a+b+c+d);
}
