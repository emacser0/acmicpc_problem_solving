#include <stdio.h>
int n,s;
int
main() {
  for(int i=0;i<5;i++) {
    scanf("%d",&n);
    s+=n;
  }
  printf("%d\n",s);
}
