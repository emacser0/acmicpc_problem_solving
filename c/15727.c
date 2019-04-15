#include <stdio.h>
int l;
int
main() {
  scanf("%d",&l);
  printf("%d\n",l/5+(l%5>0));
}
