#include <stdio.h>
char buf[104];
int t,x;
int
main() {
  while(scanf("%d",&t),x=0,t) {
    getchar();
    for(int i=0;i<t;i++) {
      fgets(buf,104,stdin);
      for(;buf[x]!=' '&&buf[x]!='\n'&&buf[x]!='\0';x++);
    }
    printf("%d\n",x+1);
  }
}
