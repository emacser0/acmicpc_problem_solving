#include <stdio.h>
int n,a,b,s;
int
main() {
  scanf("%d",&n);
  for(int i=0;i<n;i++) {
    scanf("%d%d",&a,&b);
    s+=b-(b/a)*a;
  }
  printf("%d\n",s);
}
