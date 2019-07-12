#include <iostream>
int N, a, b, cnt;
char map[104][104];
int main()
{
  std::cin >> N;
  for(int i = 0; i < N; ++i)
  {
    std::cin >> a >> b;
    for(int j = 0; j < 10; ++j)
    {
      for(int k = 0; k < 10; ++k)
      {
        if(map[a + j][b + k] == 0)
        {
          map[a + j][b + k] = 1;
          cnt += 1;
        }
      }
    }
  }
  std::cout << cnt << "\n";
}
