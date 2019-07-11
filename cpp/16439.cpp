#include <iostream>
int N, M, arr[34][34];
int Max(int a, int b)
{
  return a > b ? a : b;
}
int main()
{
  std::cin >> N >> M;
  int t;
  for(int i = 0; i < N; ++i)
  {
    for(int j = 0; j < M; ++j)
    {
      std::cin >> arr[i][j];
    }
  }
  int max = 0;
  for(int i = 0; i < M; ++i)
  {
    for(int j = i + 1; j < M; ++j)
    {
      for(int k = j + 1; k < M; ++k)
      {
        int sum = 0;
        for(int l = 0; l < N; ++l)
        {
          sum += Max(arr[l][i], Max(arr[l][j], arr[l][k]));
        }
        max = Max(max, sum);
      }
    }
  }
  std::cout << max << "\n";
}
