#include <stdio.h>
char ch;
int c;
int
main() {
  while((ch=getchar())!='\n') {
    if(ch==',')c++;
  }
  printf("%d\n",c+1);
}
