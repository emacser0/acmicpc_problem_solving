#include <stdio.h>
int t,a,b,ret[10000];

int
main() {
  scanf("%d",&t);
  for(int i=0;i<t;i++) {
    scanf("%d%d",&a,&b);
    ret[i]=a+b;
  }
  for(int i=0;i<t;i++) {
    printf("%d\n",ret[i]);
  }
}
