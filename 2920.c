#include <stdio.h>
int a=1,d=8,af=1,df=1,n;

int
main() {
  for(;~scanf("%d",&n);) {
    af=n==a++&&af?1:0;
    df=n==d--&&df?1:0;
  }
  puts(af?"ascending":df?"descending":"mixed");
}
