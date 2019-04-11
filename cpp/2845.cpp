#include <cstdio>
int l,p;
int
main() {
  scanf("%d%d",&l,&p);
  l*=p;
  for(int i=0;i<5;i++) {
    scanf("%d",&p);
    printf("%d ",p-l);
  }
  printf("\n");
}
