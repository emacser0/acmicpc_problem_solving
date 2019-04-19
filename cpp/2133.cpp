#include <stdio.h>
int N,dp[99];
int main() {
  scanf("%d",&N);
  dp[0]=1;
  for(int i=2;i<=N;i+=2) {
    dp[i]=dp[i-2];
    for(int j=0;j<i;j+=2) {
      dp[i]+=dp[j]*2;
    }
  }
  printf("%d\n",dp[N]);
}
