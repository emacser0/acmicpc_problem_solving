#include <stdio.h>
typedef long long int llint;

llint a,b;

llint lcm(llint,llint);

int
main() {  
  scanf("%lld %lld",&a,&b);
  printf("%lld\n",lcm(a,b));
}

llint
lcm(llint a,llint b) {
  llint x=a,y=b,z=b;
  for(;y!=0;) {
    z=x%y;
    x=y;
    y=z;
  }
  return a*b/x;
}
