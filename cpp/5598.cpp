#include <cstdio>
char caesar[27]="XYZABCDEFGHIJKLMNOPQRSTUVW",str[101];
int
main() {
  scanf("%s",str);
  for(int i=0;str[i]!='\0';i++) {
    putchar(caesar[str[i]-'A']);
  }
  puts("");
}
