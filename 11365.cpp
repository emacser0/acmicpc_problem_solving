#include <cstdio>
#include <cstring>
char buf[504];
int len;
int
main() {
  while(fgets(buf,504,stdin)!=NULL) {
    if(!strncmp(buf,"END",3)) {
      break;
    }
    len=strlen(buf);
    buf[len-1]='\0';
    len--;
    for(int i=len-1;i>=0;i--) {
      putchar(buf[i]);
    }
    puts("");
  }
}
