#include <stdio.h>
int n,f[1000004];
int
main() {
  f[0]=1;
  f[1]=2;
  scanf("%d",&n);
  for(int i=2;i<n;i++) {
    f[i]=(f[i-1]+f[i-2])%15746;
  }
  printf("%d\n",f[n-1]);
}
