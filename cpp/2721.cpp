#include <stdio.h>
long long T,n,s,dp[302];
int main() {
  for(int i=1;i<302;i++) {
    dp[i]=dp[i-1]+i;
  }
  scanf("%d",&T);
  for(int i=0;i<T;i++,s=0) {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
      s+=i*dp[i+1];
    }
    printf("%d\n",s);
  }
}
