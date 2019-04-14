#include <stdio.h>
int n,t,s;
int
main() {
  scanf("%d",&n);
  for(int i=0;i<n;i++) {
    scanf("%d",&t);
    if(t!=i+1)s++;
  }
  printf("%d\n",s);
}
