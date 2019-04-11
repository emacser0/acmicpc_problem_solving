#include <cstdio>
int t,v,e;
int
main() {
  scanf("%d",&t);
  for(int i=0;i<t;i++) {
    scanf("%d%d",&v,&e);
    printf("%d\n",2-v+e);
  }
}
