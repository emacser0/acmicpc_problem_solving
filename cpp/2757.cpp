#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[99],stack[99],si;
int a,b;
int main() {
  while(scanf("R%s",s),getchar(),strcmp(s,"0C0")) {
    a=atoi(strtok(s,"C"));
    b=atoi(strtok(NULL,"C"));
    si=0;
    while(b){
      b--;
      stack[si++]='A'+b%26;
      b/=26;
    };
    for(int i=si-1;i>=0;i--) {
      putchar(stack[i]);
    }
    printf("%d\n",a);
  }
}
