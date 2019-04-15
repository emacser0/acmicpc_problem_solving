#include <stdio.h>
#include <stdlib.h>
int a,b,c,d,x,y,z,w,r;
int
main() {
  while(scanf("%d %d %d %d",&a,&b,&c,&d),a+b+c+d) {
    r=0;
    while(!(a==b&&b==c&&c==d)) {
      x=abs(a-b),y=abs(b-c),z=abs(c-d),w=abs(d-a);
      a=x,b=y,c=z,d=w;
      r++;
    }
    printf("%d\n",r);
  }
}
