#include <stdio.h>
int r,c;
int
main() {
  scanf("%d\n%d",&r,&c);
  for(int i=0;i<r;i++) {
    for(int j=0;j<c;j++) {
      putchar('*');
    }
    puts("");
  }
}
