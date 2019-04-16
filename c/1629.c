#include <stdio.h>
long long a,b,c;
long long pow(int x,int y) {
    if(y<2)return x;
    if(y%2) {
        return x%c*pow(x,y-1)%c;
    }
    else {
        long long t=pow(x,y/2);
        return (t%c*t%c)%c;
    }
}
int
main() {
  scanf("%d%d%d",&a,&b,&c);
  printf("%lld\n",pow(a,b)%c);
}
