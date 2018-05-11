#include <stdio.h>
int ch;

int
main() {
  ch=getchar();
  for(;ch!=EOF;ch=getchar()) {
    putchar(ch);
  }  
}       
