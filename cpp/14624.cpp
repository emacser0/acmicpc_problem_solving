#include <iostream>
int n, s, e;
int main()
{
  std::cin >> n;
  if(n % 2 == 0)
  {
    std::cout << "I LOVE CBNU\n";
  }
  else
  {
    s = e = n / 2;
    for(int i = 0; i < n; ++i)
    {
      std::cout << "*";
    }
    std::cout << "\n";
    for(int i = 0; i < (n / 2 + 1); ++i, --s, ++e)
    {
      for(int j = 0; j < n; ++j)
      {
        std::cout << (j == s || j == e ? "*" : " ");
        if(j == e)
        {
          break;
        }
      }
      std::cout << "\n";
    }
  }
}
