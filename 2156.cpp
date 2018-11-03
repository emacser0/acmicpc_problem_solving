#include <iostream>
#include <cmath>
int n,gj[10001],dp[10001];
int
max3(int x,int y,int z) {
  return std::max(std::max(x,y),z);
}
int
main() {
  std::ios_base::sync_with_stdio(false);
  std::cin >> n;
  for(int i=0;i<n;i++) {
    std::cin >> gj[i];
  }
  dp[0]=gj[0];
  dp[1]=gj[0]+gj[1];
  for(int i=2;i<n;i++) {
    dp[i]=max3(dp[i-3]+gj[i-1]+gj[i],dp[i-2]+gj[i],dp[i-1]);
  }
  std::cout << dp[n-1] << "\n";
}
