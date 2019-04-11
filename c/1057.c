#include <stdio.h>
int
main() {
  int n,a,b,i;
  scanf("%d%d%d",&n,&a,&b);
  a--,b--;
  for(i=0;a!=b;i++) {
    a/=2,b/=2;    
  }
  printf("%d\n",i);
}
