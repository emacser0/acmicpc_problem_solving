#include <iostream>
#include <cmath>
int n,p[10001],dp[1001];
int
main() {
  std::ios_base::sync_with_stdio(false);
  std::cin >> n;
  for(int i=0;i<n;i++) {
    std::cin >> p[i];
  }
  for(int i=n;i>=0;i--) {
    for(int j=0;j<n;j++) {
      if(i-j-1>=0) {
        dp[i-j-1]=std::max(dp[i-j-1],dp[i]+p[j]);
      }
    }
  }
  std::cout << dp[0] << "\n";
}
