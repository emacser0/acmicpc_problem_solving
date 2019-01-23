#include <cstdio>
int a,b,v,i;
int
main() {
  scanf("%d%d%d",&a,&b,&v);  
  printf("%d\n",(v-b-1)/(a-b)+1);
}
