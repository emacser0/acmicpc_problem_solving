#include <iostream>
int N, R, C;
int main()
{
  std::cin >> N >> R >> C;
  R--, C--;
  int mode = (!(R % 2) && !(C % 2)) || (R % 2 && C % 2);
  for(int i = 0; i < N; ++i)
  {
    for(int j = 0; j < N; ++j)
    {
      std::cout << (((mode == i % 2) == j % 2) ? 'v' : '.');
    }
    std::cout << "\n";
  }
}
