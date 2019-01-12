#include <cstdio>
int n,k,p[101],dp[10001],max;
int
main() {
  scanf("%d%d",&n,&k);
  for(int i=0;i<n;i++) {
    scanf("%d",&p[i]);
    max=max>p[i]?max:p[i];
  }
  dp[0]=1;
  for(int i=0;i<n;i++) {
    for(int j=p[i];j<=k;j++) {
      dp[j]+=dp[j-p[i]];
    }
  }
  printf("%d\n",dp[k]);
}
