#include <stdio.h>
int t,a,b,c,d,e,f,g,h;
int
main() {
  scanf("%d",&t);
  for(int i=0;i<t;i++) {
    scanf("%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g,&h);
    a=a+e<1?1:a+e;
    b=b+f<1?1:b+f;
    c=c+g<0?0:c+g;
    d+=h;
    printf("%d\n",a+5*b+2*c+2*d);
  }  
}
