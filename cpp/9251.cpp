#include <iostream>
#include <cstring>
char sa[1004], sb[1004];
int dp[1004][1004];
int Max(int a,  int b)
{
  return a > b ? a : b;
}
int Min(int a, int b)
{
  return a < b ? a : b;
}
int main()
{
  std::cin >> sa >> sb;
  int len_a = strlen(sa) , len_b = strlen(sb);
  for(int i = 1; i <= len_a; ++i)
  {
    for(int j = 1; j <= len_b; ++j)
    {
      if(sa[i - 1] == sb[j - 1])
      {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      }
      else
      {
        dp[i][j] = Max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  std::cout << dp[len_a][len_b] << "\n";
}
