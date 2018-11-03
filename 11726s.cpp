#include <cstdio>
int n,dp[1001]={1,2};int main(){scanf("%d",&n);for(int i=2;i<n;i++){dp[i]=(dp[i-2]+dp[i-1])%10007;}printf("%d",dp[n-1]);}
