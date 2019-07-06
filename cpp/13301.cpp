#include <iostream>
long long n, a = 2, b = 2;
int main()
{
  std::cin >> n;
  for(int i = 0; i < n; ++i)
  {
    b += a;
    a = b - a;
  }
  std::cout << b << "\n";
}
