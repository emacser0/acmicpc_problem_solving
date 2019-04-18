#include <stdio.h>
#include <stdlib.h>
int isnp[1000009]={1,1,},m,n;
int
main() {
  scanf("%d%d",&m,&n);
  for(int i=2;i*i<n;i++) {
    if(!isnp[i])for(int j=2;i*j<=n;j++)isnp[i*j]=1;
  }
  for(int i=m;i<=n;i++) {
    if(!isnp[i])printf("%d\n",i);
  }
}
