#include <stdio.h>
long long T,n,dp[1000004]={0,1,2,4},m=1e9+9;
int main() {
  for(int i=4;i<=1e6;i++) {
      dp[i]=(dp[i-3]+dp[i-2]+dp[i-1])%m;
  }
  scanf("%d",&T);
  while(T--) {
    scanf("%d",&n);
    printf("%d\n",dp[n]);
  }
}
