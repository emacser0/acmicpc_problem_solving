#include <iostream>
int n;
const long long m=1000000000;
long long dp[100][10],sum;
int
main() {
  std::ios_base::sync_with_stdio(false);
  std::cin >> n;
  for(int i=1;i<10;i++) {
    dp[0][i]=1;
  }
  for(int i=0;i<n-1;i++) {
    dp[i+1][0]+=dp[i][1];
    dp[i+1][0]%=m;
    dp[i+1][9]+=dp[i][8];
    dp[i+1][9]%=m;
    for(int j=1;j<9;j++) {
      dp[i+1][j]=dp[i][j-1]+dp[i][j+1];
      dp[i+1][j]%=m;
    }
  }
  for(int i=0;i<10;i++) {
    sum+=dp[n-1][i];
    sum%=m;
  }
  std::cout << sum  << "\n";
}
