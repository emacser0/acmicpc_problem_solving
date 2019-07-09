#include <iostream>
int N, A, k;
int main()
{
  std::cin >> N >> A;
  while(N)
  {
    N /= A;
    k += N;
  }
  std::cout << k << "\n";
}
