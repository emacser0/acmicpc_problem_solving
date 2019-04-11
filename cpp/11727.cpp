#include <iostream>
int n,dp[1001];
const int m=10007;
int
main() {
  std::ios_base::sync_with_stdio(false);
  std::cin >> n;
  dp[0]=1;
  dp[1]=3;
  for(int i=2;i<n;i++) {
    dp[i]=(dp[i-1]+dp[i-2]*2)%10007;
  }
  std::cout << dp[n-1] << "\n";
}
