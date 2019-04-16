#include <stdio.h>
int x,y,c,s,f;
int
main() {
  scanf("%d%d",&x,&y);
  for(int i=1;;i++) {
    for(int j=0;j<i;j++) {
      c++;
      if(c>=x&&c<=y)s+=i;
      if(c>y){f=1;break;}
    }
    if(f)break;
  }
  printf("%d\n",s);
}
