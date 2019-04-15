#include <stdio.h>
int k,a,b,t;
int
main() {
  scanf("%d%d%d",&k,&a,&b);
  if(a<b){t=a;a=b;b=t;}
  printf("%f",k*k-(a/2.0-b/2.0)*(a/2.0-b/2.0));
}
