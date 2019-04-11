#include <stdio.h>
int n,c;

int
main() {
  for(;~scanf("%d",&n);c+=n>0?1:0);
  printf("%d\n",c);
}
