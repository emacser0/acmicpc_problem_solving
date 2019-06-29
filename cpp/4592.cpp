#include <iostream>
int n, t, pt;
int main()
{
  while(std::cin >> n, n > 0)
  {
    pt = 0;
    for(int i = 0; i < n; ++i)
    {
      std::cin >> t;
      if(t != pt)
      {
        std::cout << t << " ";
      }
      pt = t;
    }
    std::cout << "$\n";
  }
}
