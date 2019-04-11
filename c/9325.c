#include <stdio.h>
int t,s,n,p,q;

int
main() {
  scanf("%d",&t);
  for(int i=0;i<t;i++) {
    scanf("%d %d",&s,&n);
    for(int i=0;i<n;i++) {
      scanf("%d%d",&q,&p);
      s+=q*p;
    }
    printf("%d\n",s);
  }
}
