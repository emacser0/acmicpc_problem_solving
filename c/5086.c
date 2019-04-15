#include <stdio.h>
int a,b;
int
main() {
  while(scanf("%d%d",&a,&b),a+b)printf("%s\n",a%b?b%a?"neither":"factor":"multiple");
}
