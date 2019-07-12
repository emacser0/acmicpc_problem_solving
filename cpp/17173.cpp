#include <iostream>
int N, M, t, cnt[1004], sum;
int main()
{
  for(std::cin >> N >> M; std::cin >> t, M; --M)
    for(int j = 1; t * j <= N; ++j)
      if(cnt[t * j] == 0) sum += t * j, cnt[t * j] = 1;
  std::cout << sum << "\n";
}
