#include <cstdio>
int n,t=1,c=1;
int
main() {
  scanf("%d",&n);
  while(n>t) t+=6*c++;
  printf("%d\n",c);
}
