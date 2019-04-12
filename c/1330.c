#include <stdio.h>
int a,b;
int
main(){
  scanf("%d%d",&a,&b);
  printf("%s\n",a>b?">":a==b?"==":"<");
}
