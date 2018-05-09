#include <stdio.h>
int n;

int
main() {
  scanf("%d",&n);
  for(int i=0;i<n;) {
    printf("%d\n",++i);
  }    
}
