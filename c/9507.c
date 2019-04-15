#include <stdio.h>
int t,n;
long long k[70];
int
main() {
  scanf("%d",&t);
  k[0]=1,k[1]=1,k[2]=2,k[3]=4;
  for(int i=4;i<69;i++) {
    k[i]=k[i-1]+k[i-2]+k[i-3]+k[i-4];
  }
  for(int i=0;i<t;i++){
    scanf("%d",&n);
    printf("%lld\n",k[n]);
  }
}
