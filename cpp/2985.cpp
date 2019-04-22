#include <stdio.h>
int a,b,c,r1,r2;
int main() {
  scanf("%d%d%d",&a,&b,&c);
  r1=(a+b==c)|((a-b==c)<<1)|((a*b==c)<<2)|((a/b==c)<<3);
  r2=(a==b+c)|((a==b-c)<<1)|((a==b*c)<<2)|((a==b/c)<<3);
  if(r1)printf("%d%c%d=%d\n",a,r1&1?'+':r1&2?'-':r1&4?'*':'/',b,c);
  else printf("%d=%d%c%d\n",a,b,r2&1?'+':r2&2?'-':r2&4?'*':'/',c);
}
