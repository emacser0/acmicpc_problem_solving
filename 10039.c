#include <stdio.h>
int s,t,i;

int
main() {
  for(;i<5;i++) {
    scanf("%d",&t);
    s+=t>40?t:40;
  }
  printf("%d\n",s/5);
}
