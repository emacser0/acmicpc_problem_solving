#include <iostream>
#include <cstring>
int k, p, m, t, room[504], cnt;
int main()
{
  std::cin >> k;
  for(int i = 0; i < k; ++i)
  {
    memset(room, 0, 504 * sizeof(int));
    cnt = 0;
    std::cin >> p >> m;
    for(int i = 0; i < p; ++i)
    {
      std::cin >> t;
      if(room[t] != 0)
      {
        cnt += 1;
      }
      room[t]++;
    }
    std::cout << cnt << "\n";
  }
}
