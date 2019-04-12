#include <stdio.h>
char ch;
int
main() {
  while((ch=getchar())!='\n')putchar(isalpha(ch)?(isupper(ch)?'A':'a')+(13+ch-(isupper(ch)?'A':'a'))%26:ch);
}
