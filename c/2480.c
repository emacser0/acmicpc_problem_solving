#include <stdio.h>
int a,b,c;
int
main() {
  scanf("%d%d%d",&a,&b,&c);
  if(a==b&&b==c)printf("%d\n",10000+a*1000);
  else if(a==b)printf("%d\n",1000+a*100);
  else if(b==c)printf("%d\n",1000+b*100);
  else if(c==a)printf("%d\n",1000+c*100);
  else printf("%d\n",100*(a>b?c>a?c:a:b>c?b:c));
}
