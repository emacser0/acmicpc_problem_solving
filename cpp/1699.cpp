#include <iostream>
#include <cmath>
int N, dp[100004];
int Max(int a, int b)
{
  return a > b ? a : b;
}
int Min(int a, int b)
{
  return a < b ? a : b;
}
int main()
{
  std::cin >> N;
  for(int i = 1; i <= N; ++i)
  {
    dp[i] = i;
    for(int j = 1; j * j <= i; ++j)
    {
      dp[i] = Min(dp[i], dp[i - j * j] + 1);
    }
  }
  std::cout << dp[N];
}
