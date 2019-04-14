#include <stdio.h>
int n;
int
main() {
  scanf("%d",&n);
  if(n%10)printf("-1");
  else printf("%d %d %d",n/300,n%300/60,n%300%60/10);
}
