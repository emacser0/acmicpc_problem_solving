#include <stdio.h>
typedef long long int llint;

llint lcm(llint,llint);

int main() {
  int n;
  llint a,b;
  scanf("%d",&n);
  for(int i=0;i<n;i++) {
    scanf("%lld %lld",&a,&b);
    printf("%lld\n",lcm(a,b));
  }
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
