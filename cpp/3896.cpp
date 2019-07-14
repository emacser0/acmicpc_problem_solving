#include <iostream>
int T, K;
char isnotprime[1300000];
int main()
{
  for(int i = 2; i <= 1300000 / 2; ++i)
  {
    if(isnotprime[i]) continue;
    for(int j = 2; i * j <= 1300000; ++j)
    {
      isnotprime[i * j] = 1;
    }
  }
  std::cin >> T;
  while(T--)
  {
    std::cin >> K;
    if(isnotprime[K])
    {
      int i = K, j = K;
      while(isnotprime[--i]);
      while(isnotprime[++j]);
      std::cout << j - i << "\n";
    }
    else
    {
      std::cout << "0\n";
    }
  }
}
