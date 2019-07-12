#include <iostream>
int N, M, a, b, max;
int main()
{
  std::cin >> N >> M;
  max = M;
  for(int i = 0;i < N; ++i)
  {
    std::cin >> a >> b;
    M += a - b;
    if(M < 0)
    {
      max = 0;
      break;
    }
    max = max > M ? max : M;
  }
  std::cout << max << "\n";
}
