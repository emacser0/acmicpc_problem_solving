#include <cstdio>
#include <cstring>
int len,max;
char buf[5][16];
int
main() {
  for(int i=0;i<5;i++) {
    scanf("%s",buf[i]);
    len=strlen(buf[i]);
    max=max>len?max:len;
  }
  for(int i=0;i<max;i++) {
    for(int j=0;j<5;j++) {
      if(i<strlen(buf[j])) {
        putchar(buf[j][i]);
      }
    }
  }
  putchar('\n');
}
