#include <iostream>
int n, m, a, b, cnt[1004];
int main()
{
  std::cin >> n >> m;
  for(int i = 0; i < m; ++i)
  {
    std::cin >> a >> b;
    cnt[a] += 1;
    cnt[b] += 1;
  }
  for(int i = 1; i <= n; ++i)
  {
    std::cout << cnt[i] << "\n";
  }
}
