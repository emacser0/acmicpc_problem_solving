#include <iostream>
int N;
int main()
{
  std::cin >> N;
  N += 56;
  std::cout << (char)(N % 12 + 'A') << (N % 10) << "\n";
}
