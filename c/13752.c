#include <stdio.h>
int n,t;
int
main() {
  scanf("%d",&n);
  for(int i=0;i<n;i++) {
    scanf("%d",&t);
    for(int j=0;j<t;j++) {
      putchar('=');
    }
    puts("");
  }
}
