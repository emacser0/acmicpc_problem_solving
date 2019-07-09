#include <iostream>
#include <cstring>
char sa[1004], sb[1004], s[1004];
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
  int len = dp[len_a][len_b];
  int i = len_a, j = len_b;
  while(dp[i][j] > 0)
  {
    if(dp[i][j] == dp[i - 1][j])
    {
      i -= 1;
      continue;
    }
    else if(dp[i][j] == dp[i][j - 1])
    {
      j -= 1;
      continue;
    }
    s[--len] = sa[i - 1];
    i -= 1;
    j -= 1;
  }
  std::cout << dp[len_a][len_b] << "\n";
  std::cout << s << "\n";
}
