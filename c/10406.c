#include <stdio.h>
int w,n,p,t,c;
int
main() {
  scanf("%d%d%d",&w,&n,&p);
  for(int i=0;i<p;i++) {
    scanf("%d",&t);
    if(t>=w&&t<=n)c++;
  }
  printf("%d\n",c);
}
