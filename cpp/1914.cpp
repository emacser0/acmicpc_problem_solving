#include <iostream>
#include <cmath>
int N;
int count[10000] = {1, }, length = 1;
void hanoi(int n, int from, int by, int to)
{
  if(n == 1)
  {
    std::cout << from << " " << to << "\n";
    return;
  }
  hanoi(n - 1, from, to, by);
  std::cout << from << " " << to << "\n";
  hanoi(n - 1, by, from, to);

}
int main()
{
  std::cin >> N;
  for(int i = 0; i < N; ++i)
  {
    for(int j = 0; j <= length; ++j)
    {
      count[j] *= 2;
      if(j > 0 && count[j - 1] > 9)
      {
        count[j] += 1;
        count[j - 1] -= 10;
        if(j == length)
        {
          length += 1;
          break;
        }
      }
    }
  }
  count[0] -= 1;
  for(int i = length - 1; i >= 0; --i)
  {
    std::cout << count[i];
  }
  std::cout << "\n";
  if(N <= 20)
  {
    hanoi(N, 1, 2, 3);
  }
}
