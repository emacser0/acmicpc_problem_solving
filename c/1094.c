#include <stdio.h>
int
main() {
  int x,cnt=0;
  for(scanf("%d",&x);x>0;x>>=1) {
    cnt+=x&1;
  }
  printf("%d\n",cnt);
}
