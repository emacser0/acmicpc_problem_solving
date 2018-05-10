#include <stdio.h>
int i,n=1;

int
main() {
  for(scanf("%d",&i);i;i--) {
    n*=i;
  }
  printf("%d",n);
}
