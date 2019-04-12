#include <stdio.h>
int a,b,c,i;
int
main() {
  while(1) {
    scanf("%d%d%d",&a,&b,&c);
    if(a==0)break;
    printf("Case %d: %d\n",++i,(c/b)*a+(c%b>a?a:c%b));
  }
}
