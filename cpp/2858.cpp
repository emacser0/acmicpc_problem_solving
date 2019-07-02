#include <iostream>
int r, b;
int main()
{
  std::cin >> r >> b;
  for(int i = 1; i <= r + b; ++i)
  {
    while((r + b) % i != 0) ++i;
    int j = (r + b) / i;
    if(2 * (i + j - 2) == r)
    {
      std::cout << j << " " << i;
      break;
    }
  }
}
