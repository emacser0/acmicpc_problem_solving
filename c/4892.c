#include <stdio.h>
int n,i;
int
main() {
  while(scanf("%d",&n),i++,n) {
    printf("%d. %s %d\n",i,n%2?"odd":"even",(3*(3*n+n%2)/2)/9);
  }
}
