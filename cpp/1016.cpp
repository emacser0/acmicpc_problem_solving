#include <iostream>
#include <cmath>
long long min, max, cnt;
char isdivided[1000004];
int main()
{
  std::cin >> min >> max;
  for(long long i = 2; i * i <= max; ++i)
    for(long long j = min / (i * i); i * i * j <= max; ++j)
      if(i *i * j >= min) isdivided[i * i * j - min] = 1;
  for(long long i = min; i <= max; ++i)
    if(!isdivided[i - min]) cnt += 1;
  std::cout << cnt << "\n";
}
