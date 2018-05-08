#include <stdio.h>
#include <math.h>
typedef unsigned long long int ullint;

ullint gcd(ullint,ullint);

int
main() {
  int x,y;
  ullint a=0,b=0;
  scanf("%d %d",&x,&y);
  for(;x>=0;){
    a+=pow(10,--x);
  }
  for(;y>=0;) {
    b+=pow(10,--y);
  }
  printf("%lld\n",gcd(a,b));

}

ullint
gcd(ullint a,ullint b) {
  ullint x=a,y=b,z=b;
  for(;y!=0;) {
    z=x%y;
    x=y;
    y=z;
  }
  return x;
}
