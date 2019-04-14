#include <stdio.h>
int n,a,b,x=100,y=100;
int
main() {
  scanf("%d",&n);
  for(int i=0;i<n;i++) {
    scanf("%d%d",&a,&b);
    if(a>b)y-=a;
    else if(a<b)x-=b;
  }
  printf("%d\n%d\n",x,y);
}
