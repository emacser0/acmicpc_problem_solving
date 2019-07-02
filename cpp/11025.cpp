#include <iostream>
int n, k, r;
int main()
{
  std::cin >> n >> k;
  r = 1;
  for(int i = 2; i <= n; ++i)
  {
    r = (r + k - 1) % i + 1;
  }
  std::cout << r << "\n";
}
