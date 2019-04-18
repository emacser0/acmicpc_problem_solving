#include <stdio.h>
char a[24],b[24],c[9];
int n,x,y;
int
main() {
  while(scanf("%s %s",a,b),a[0]!='#'||b[0]!='#') {
    scanf("%d\n",&n);
    x=0,y=0;
    for(int i=0;i<n;i++) {
      fgets(c,8,stdin);
      if(c[0]==c[2])x++;
      else y++;
    }
    printf("%s %d %s %d\n",a,x,b,y);
  }
}
