#include <iostream>
int T, K;
int main()
{
  std::cin >> T;
  for(int i = 0; i < T; ++i)
  {
    std::cin >> K;
    long long p = 1;
    for(int i = 0; i < K; ++i)
    {
      p *= 2;
    }
    std::cout << p - 1 << "\n";
  }
}
