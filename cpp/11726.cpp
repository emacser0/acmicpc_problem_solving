#include <iostream>
int n,dp[1001]={1,2};
int
main()
{
  std::cin >> n;
  for(int i=2;i<n;i++)
  {
    dp[i]=(dp[i-2]+dp[i-1])%10007;
  }
  std::cout << dp[n-1] << "\n";
}
