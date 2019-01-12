#include <cstdio>
char table[10]="CAMBRIDGE",str[101];
int
main() {
  scanf("%s",str);
  for(int i=0;str[i]!='\0';i++) {
    int cond=1;
    for(int j=0;j<9;j++) {
      if(str[i]==table[j]) {
        cond=0;
        break;
      }
    }
    if(cond) {
      putchar(str[i]);
    }
  }
  puts("");
}
