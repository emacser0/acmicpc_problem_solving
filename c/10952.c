#include <stdio.h>
int a,b;

int
main() {  
  for(;~scanf("%d%d",&a,&b)&&(a!=0&&b!=0);) {
    printf("%d\n",a+b);
  }
}
