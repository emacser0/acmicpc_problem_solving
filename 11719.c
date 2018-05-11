#include <stdio.h>
int ch;

int
main() {
  for(;(ch=getchar())!=EOF;) {
    putchar(ch);
  }
}
