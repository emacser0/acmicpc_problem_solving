#include <cstdio>
int t,n,m,r=1;
int
main() {
  scanf("%d",&t);
  for(int i=0;i<t;i++) {
    scanf("%d%d",&n,&m);
    for(int j=1;j<=n;j++) {
      r=(r*(m-j+1))/j;
    }
    printf("%d\n",r);
    r=1;
  }
}
