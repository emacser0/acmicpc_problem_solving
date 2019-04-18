#include <stdio.h>
#include <string.h>
char s[84],l;
int
main() {
  while(fgets(s,81,stdin),s[0]!='*'||s[1]!='*'||s[2]!='*') {
    l=strlen(s);
    for(int i=l-2;i>=0;i--) {
      putchar(s[i]);
    }
    puts("");
  }
}
