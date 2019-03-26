#include <cstdio>
#define MAX(a,b) a>b?a:b
int a,b,c;
int
main() {
  scanf("%d%d%d",&a,&b,&c);
  printf("%d\n",MAX(c-b-1,b-a-1));
}
