#include <iostream>

#define SSFOR(x, s, e) for(x = s; x < e; ++x)

template <typename T>
T Max(T a, T b)
{
  return a > b ? a : b;
}

template <typename T>
T Min(T a, T b)
{
  return a < b ? a : b;
}

int K, N, arr[504], sum[504][504], dp[504][504];

int main()
{
  std::cin >> K;
  int q;
  SSFOR(q, 0, K)
  {
    std::cin >> N;
    int e;
    SSFOR(e, 0, N)
    {
      std::cin >> arr[e];
    }
    int i, j;
    SSFOR(i, 1, N)
    {
      SSFOR(j, 0, N)
      {
        if(j + i < N)
        {
          dp[j][j + i] = 2e9;
          int k;
          SSFOR(k, j, j + i)
          {
            dp[j][j + i] = Min(dp[j][j + i], dp[j][k] + dp[k + 1][j + i]);
          }
          SSFOR(k, j, j + i + 1)
          {
            dp[j][j + i] += arr[k];
          }
        }
        else
        {
          break;
        }
      }
    }
    std::cout << dp[0][N - 1] << "\n";
  }
}
