#include <stdio.h>
int x,y;
int
main() {
  scanf("%d%d",&x,&y);
  printf("%d\n",x>0?y>0?1:4:y>0?2:3);
}
