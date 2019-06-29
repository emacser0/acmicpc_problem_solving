#include <iostream>
int n, k, t;
int main()
{
  std::cin >> n >> k;
  for(int i = 0; i < k; ++i)
  {
    std::cin >> t;
    n -= t / 2 + t % 2;
  }
  std::cout << (n <= 0 ? "YES" : "NO") << "\n";
}
