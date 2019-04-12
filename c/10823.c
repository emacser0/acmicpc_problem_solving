#include <stdio.h>
#include <ctype.h>
int stack[1000],si,ch,mul=1,sum;
int
main() {
  while(1) {
    ch=getchar();
    if(isdigit(ch))stack[si++]=ch-'0';
    else if(ch!='\n') {
      while(si>-1) {
        sum+=stack[--si]*mul;
        mul*=10;
      }
      mul=1;
      if(ch==EOF)break;
    }
  }
  printf("%d\n",sum);
}
