#include <stdio.h>
#include <ctype.h>
char buf[1000004];
int
main() {
  scanf("%s",buf);
  for(int i=0;buf[i]!='\0';i++) {
    buf[i]=toupper(buf[i]);
  }
  printf("%s\n",buf);
}
