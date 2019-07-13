#include <iostream>
#include <cstring>
int M, N, isnotprime[10004] = {1, 1};
template <typename T>
T Min(T a, T b) { return a < b ? a : b; }
int main()
{
  std::cin >> M >> N;
  for(int i = 2; i < N / 2; ++i)
  {
    if(isnotprime[i] == 1) continue;
    for(int j = 2; i * j <= N; ++j)
    {
      isnotprime[i*j] = 1;
    }
  }
  int sum = 0, min = 2e9;
  for(int i = M; i <= N; ++i)
  {
    if(isnotprime[i] == 0)
    {
      sum += i;
      min = Min(min, i);
    }
  }
  if(sum == 0) std::cout << -1 << "\n";
  else std::cout << sum << "\n" << min << "\n";
}
