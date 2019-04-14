#include <stdio.h>
int p=-2e9,n,f;
int
main() {
  while(~scanf("%d",&n)) {
    if(n-p<0){f=1;break;}
    p=n;
  }
  printf("%s\n",f?"Bad":"Good");
}
