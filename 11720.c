#include <stdio.h>
int a,b,i;
char buf[99];

int
main() {
  scanf("%d",&b);
  for(scanf("%s",buf);i<b;i++) {
    a+=buf[i]-48;
  }    
  printf("%d\n",a);
}
