#include <stdio.h>
#define swap(x,y) {t=x;x=y;y=t;}
int a,b,c,t,d;
int main() {
  scanf("%d%d%d",&a,&b,&c);
  if(a>b)swap(a,b);
  if(a>c)swap(a,c);
  if(b>c)swap(b,c);
  d=b-a;
  printf("%d\n",d>(c-b)?a+c-b:d<(c-b)?b+d:c*2-b);
}
