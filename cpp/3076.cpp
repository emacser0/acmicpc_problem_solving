#include <iostream>
int R, C, A, B;
int main()
{
  std::cin >> R >> C >> A >> B;
  for(int i = 0; i < R * A; ++i)
  {
    for(int j = 0; j < C * B; ++j)
      std::cout << (i / A % 2 ^ j / B % 2 ? '.' : 'X');
    std::cout << "\n";
  }
}
