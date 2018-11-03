#include <iostream>
int n,nums[100000],dp[100000];
int
main() {
  std::ios_base::sync_with_stdio(false);
  std::cin >> n;
  for(int i=0;i<n;i++) {
    std::cin >> nums[i];
  }
  dp[0]=nums[0];
  for(int i=1;i<n;i++) {
    dp[i]=std::max(dp[i-1],0)+nums[i];
  }
  int max=-1000000000;
  for(int i=0;i<n;i++) {
    max=std::max(max,dp[i]);
  }
  std::cout << max;
}
