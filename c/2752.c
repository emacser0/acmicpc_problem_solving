#include <stdio.h>
#define swap(x,y) t=x;x=y;y=t
int a,b,c,t;
int
main() {
  scanf("%d%d%d",&a,&b,&c);
  if(a>c){swap(a,c);}
  if(a>b){swap(a,b);}
  if(b>c){swap(b,c);}
  printf("%d %d %d\n",a,b,c);
}
