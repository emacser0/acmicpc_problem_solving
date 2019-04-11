#include <cstdio>
#include <cstring>
char str[1000003],boom[40],stack[1000001];
int str_len,boom_len,si;
int
main() {
  scanf("%s %s",str,boom);
  str_len = strlen(str);
  boom_len = strlen(boom);
  for(int i=0;i<str_len;i++) {
    stack[si++]=str[i];
    if(si>=boom_len&&!strncmp(stack+si-boom_len,boom,boom_len)) {
      si-=boom_len;
    }
  }
  stack[si]='\0';
  printf("%s\n",si?stack:"FRULA");
}
