#include <stdio.h>
long long n,t[35],s;
int
main() {
  scanf("%d",&n);
  t[0]=1;
  for(int i=1;i<=n;i++) {
    s=0;
    for(int j=0;j<i;j++) {
      s+=t[j]*t[i-j-1];
    }
    t[i]=s;
  }
  printf("%lld\n",t[n]);
}
