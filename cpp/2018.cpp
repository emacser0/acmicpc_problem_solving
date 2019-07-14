#include <iostream>
int N, cnt = 1;
int main()
{
  std::cin >> N;
  for(int i = N / 2 + 1; i > 0; --i)
  {
    int sum = 0;
    for(int j = i; sum < N; sum += j, ++j);
    if(sum == N) cnt += 1;
  }
  std::cout << cnt << "\n";
}
