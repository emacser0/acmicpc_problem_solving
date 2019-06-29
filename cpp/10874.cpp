#include <iostream>
int n, t, cnt;
int main()
{
  std::cin >> n;
  for(int i = 0; i < n; ++i)
  {
    cnt = 0;
    for(int j = 1; j <= 10; ++j)
    {
      std::cin >> t;
      if(t == (j - 1) % 5 + 1)
      {
        cnt += 1;
      }
    }
    if(cnt == 10)
    {
      std::cout << i + 1 << "\n";
    }
  }
}
