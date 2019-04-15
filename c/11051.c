#include <stdio.h>
int n,k,r,c[1001][1001];
int
main() {
  scanf("%d%d",&n,&k);
  for(int i=1;i<=n;i++) {
    for(int j=0;j<=n;j++) {
      if(j==0||i==j)c[i][j]=1;
      else c[i][j]=(c[i-1][j-1]+c[i-1][j])%10007;
    }
  }
  printf("%d\n",c[n][k]);
}
