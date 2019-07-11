#include <iostream>
#include <cmath>
int N;
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
  std::cout << (int)pow(2, N) - 1 << "\n";
  hanoi(N, 1, 2, 3);
}
