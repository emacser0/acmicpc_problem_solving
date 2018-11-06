#include <iostream>
int n,a[1001],dp[1001],max,maxl=1;
int
main() {
  std::ios_base::sync_with_stdio(false);
  std::cin >> n >> a[0];
  dp[0]=1;
  for(int i=1;i<n;i++) {
    std::cin >> a[i];
    for(int j=0;j<n;j++) {
      if(max<dp[j]&&a[i]>a[j]) {
        max=dp[j];
      }
    }
    dp[i]=max+1;
    max=0;
    maxl=std::max(maxl,dp[i]);
  }
  std::cout << maxl << "\n";
}
