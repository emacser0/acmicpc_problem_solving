#include <iostream>
int T, a, b;
int main()
{
  std::cin >> T;
  for(int i = 0; i < T; ++i)
  {
    std::cin >> a >> b;
    std::cout << "Case " << i + 1 << ": " << a + b << "\n";
  }
}
