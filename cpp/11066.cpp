#include <iostream>
#define For(x, s, e) for(int x = s; x < e; ++x)
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

int K, N, arr[504], dp[504][504];
int main()
{
  std::cin >> K;
  int q;
  For(q, 0, K)
  {
    std::cin >> N;
    For(e, 0, N)
    {
      std::cin >> arr[e];
    }
    For(i, 1, N)
    {
      For(j, 0, N)
      {
        if(j + i < N)
        {
          dp[j][j + i] = 2e9;
          For(k, j, j + i)
          {
            dp[j][j + i] = Min(dp[j][j + i], dp[j][k] + dp[k + 1][j + i]);
          }
          For(k, j, j + i + 1)
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
