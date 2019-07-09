#include <iostream>
int T, N;
int main()
{
  std::cin >> T;
  for(int i = 0; i < T; ++i)
  {
    std::cin >> N;
    for(int j = 2; j <= N; ++j)
    {
      int cnt = 0;
      while(N % j == 0)
      {
        cnt += 1;
        N /= j;
      }
      if(cnt > 0)
      {
        std::cout << j << " " << cnt << "\n";
      }
    }
  }
}
