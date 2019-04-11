#include <cstdio>
int m,i,x,y,c=1;
int
main() {
  for(scanf("%d",&m);i<m;i++) {
    scanf("%d%d",&x,&y);
    c=x==c?y:y==c?x:c;
  }
  printf("%d\n",c);
}
