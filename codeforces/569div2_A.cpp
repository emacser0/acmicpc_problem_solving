#include <iostream>
#include <cmath>
int n, r = 1;
int main()
{
  std::cin >> n;
  if(n > 1) r += 2 * (n - 1) * n;
  std::cout << r << "\n";
}
