#include <stdio.h>
int n,k,nfac=1,kfac=1,nmkfac=1;

int
main(){
  scanf("%d %d",&n,&k);
  for(int i=1;i<=n;i++) {
    nfac*=i;
  }
  for(int i=1;i<=k;i++) {
    kfac*=i;
  }
  for(int i=1;i<=n-k;i++) {
    nmkfac*=i;
  }
  printf("%d\n",nfac/(kfac*nmkfac));
}
