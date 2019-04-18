#include <stdio.h>
int n,a,b,c;
int
main() {
  scanf("%d",&n);
  printf("Gnomes:\n");
  for(int i=0;i<n;i++) {
    scanf("%d%d%d",&a,&b,&c);
    puts((a<=b&&b<=c)||(a>=b&&b>=c)?"Ordered":"Unordered");
  }
}
