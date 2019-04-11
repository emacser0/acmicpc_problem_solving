#include <cstdio>
#define MIN(a,b) (a<b?a:b)
int x,y,w,h;
int
main() {
  scanf("%d%d%d%d",&x,&y,&w,&h);
  printf("%d\n",MIN(MIN(MIN(x,y),w-x),h-y));
}
