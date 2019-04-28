#include <stdio.h>
int a,b,x,y,t;
int main() {
  scanf("%d:%d",&a,&b);
  x=a,y=b;
  while(y) t=x%y,x=y,y=t;
  printf("%d:%d\n",a/x,b/x);
}
