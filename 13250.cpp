#include <iostream>
int n;
constexpr double dice_p=1.0/6;
double dp[1000001];
int
main() {
  std::cin >> n;
  dp[0]=0;
  dp[1]=1;
  for(int i=2;i<6;i++) {
    dp[i]+=dice_p*(6-i);
  }
  for(int i=2;i<=n;i++) {
    for(int j=1;j<7;j++) {
      if(i-j>=0) {
        dp[i]+=dice_p*(dp[i-j]+1);
      }
    }
  }
  std::cout.precision(10);
  std::cout << dp[n] << "\n";
}
