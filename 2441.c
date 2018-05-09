#include <stdio.h>
int n;

int
main() {
  scanf("%d",&n);
  for(int i=0;i<n;i++) {
    for(int j=0;j<=n;j++) {
      putchar(j<i?32:"*\n"[j==n]);
    }
  }      
}
