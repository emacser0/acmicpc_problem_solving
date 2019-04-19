#include <stdio.h>
long long N,dp[104];
int main() {
  for(int i=1;i<101;i++) {
    dp[i]=dp[i-1]+i*i;
  }
  while(scanf("%d",&N),N) {
    printf("%d\n",dp[N]);
  }
}
