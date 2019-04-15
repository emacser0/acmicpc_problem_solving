#include <stdio.h>
int a,b;
char s[5];
int
main() {
  while(scanf("%d%s%d",&a,s,&b),a!=0||s[0]!='W'||b!=0) {
    if(s[0]=='W'&&a-b<-200)printf("Not allowed\n");
    else printf("%d\n",a+(s[0]=='D'?b:-b));
  }
}
