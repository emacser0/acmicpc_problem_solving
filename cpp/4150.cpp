#include <iostream>
int N;
int a[1009] = {1, }, b[1009] = {1, };
int main()
{
  std::cin >> N;
  for(int i = 3; i <= N; ++i)
  {
    for(int i = 0; i <= N; ++i)
    {
      b[i] += a[i];
      if(b[i] > 9) b[i] -= 10, b[i + 1] += 1;
    }
    for(int i = 0; i <= 1000; ++i)
    {
      a[i] = b[i] - a[i];
    }
    for(int i = 0; i <= 1000; ++i)
    {
      if(a[i] < 0) a[i] += 10, a[i + 1] -= 1;
    }
  }
  int e = 1000;
  for(; e >= 0 && b[e] == 0; --e);
  for(int i = e; i >= 0; --i)
  {
    std::cout << b[i];
  }
  std::cout << "\n";
}
