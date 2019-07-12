#include <iostream>
int D, K;
int main()
{
  std::cin >> D >> K;
  int flag = 1, f1 = 0, f2 = 1, a = 0, b = 0;
  for(int i = 2; i < D; ++i)
  {
    f2 = f1 + f2;
    f1 = f2 - f1;
  }
  for(int i = 1; flag && i <= 50000; ++i)
  {
    for(int j = i; j <= 50000; ++j)
    {
      int r = f1 * i + f2 * j;
      if(r > K) break;
      if(r == K)
      {
        std::cout << i << "\n" << j << "\n";
        flag = 0;
        break;
      }
    }
  }
}
