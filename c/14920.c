#include <stdio.h>
int n,c;
int
main() {
  scanf("%d",&n);
  while(n>1){
    n=n%2?3*n+1:n/2;
    c++;
  }
  printf("%d\n",c+1);
}
