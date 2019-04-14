#include <stdio.h>
int n,t,max=-2e9,min=2e9;
int
main() {
  scanf("%d",&n);
  for(int i=0;i<n;i++) {
    scanf("%d",&t);
    max=max>t?max:t;
    min=min>t?t:min;
  }
  printf("%d %d\n",min,max);
}
