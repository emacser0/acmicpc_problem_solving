#include <stdio.h>
int a,b,c,d,x,y,r;
int
main() {
  scanf("%d%d%d%d",&a,&b,&c,&d);
  scanf("%d%d%d",&x,&y,&r);
  printf("%d\n",a==x?1:b==x?2:c==x?3:d==x?4:0);
}
