#include <vector>
long long sum(std::vector<int> &v)
{
  long long r = 0;
  for(auto &i : v) r += i;
  return r;
}
