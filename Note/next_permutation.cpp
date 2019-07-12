#include <vector>
int next_permutaiton(std::vector<int> &v)
{
  size_t i = v.size() - 1, j = v.size() - 1;
  while(i > 0 && v[i - 1] >= v[i]) --i;
  if(i <= 0) return 0;
  while(v[i - 1] >= v[j]) --j;
  swap(v[i - 1], v[j]);
  j = v.size() - 1;
  while(i < j)
  {
    swap(v[i], v[j]);
    i += 1, j -= 1;
  }
  return 1;
}
