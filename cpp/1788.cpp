#include <iostream>
#include <cmath>
int N, fib[1000000] = {0, 1};
int main()
{
  std::cin >> N;
  for(int i = 2; i <= abs(N); ++i)
    fib[i] = (fib[i - 1] + fib[i - 2]) % 1000000000;
  if(N == 0) std::cout << "0\n0\n";
  else std::cout << (N > 0 || abs(N) % 2 ? 1 : -1) << "\n" << fib[abs(N)] << "\n";
}
