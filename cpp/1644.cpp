#include <iostream>
int N, isnotprime[4000004], cnt;
int main()
{
  std::cin >> N;
  for(int i = 2; i * i <= N; ++i)
  {
    if(isnotprime[i]) continue;
    for(int j = i * i; j <= N; j += i) isnotprime[j] = 1;
  }
  for(int i = 2; i <= N; ++i)
  {
    int sum = 0;
    if(!isnotprime[i])
    {
      for(int j = i; j <= N && sum < N; ++j)
        if(!isnotprime[j]) sum += j;
      if(sum == N) cnt += 1;
    }
  }
  std::cout << cnt << "\n";
}
