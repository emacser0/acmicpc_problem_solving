#include <iostream>
#define max(a,b) a>b?a:b
int n,stairs[302],dp[302];
int
main() {
  std::cin >> n;
  for(int i=0;i<n;i++) {
    std::cin >> stairs[i];
  }
  dp[0]=stairs[0];
  dp[1]=stairs[0]+stairs[1];
  dp[2]=max(stairs[0]+stairs[2],stairs[1]+stairs[2]);
  for(int i=3;i<n;i++) {
    dp[i]=max(dp[i-2]+stairs[i],dp[i-3]+stairs[i-1]+stairs[i]);
  }
  std::cout << dp[n-1] << "\n";
}
