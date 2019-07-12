#include <iostream>
#include <cstdlib>
#include <cstring>
char a[9], b[9];
template <typename T>
void Swap(T &a, T &b) { T t = a; a = b; b = t; }
int main()
{
  std::cin >> a >> b;
  int len_a = strlen(a), len_b = strlen(b);
  int i = 0;
  while(i < len_a - 1 - i) Swap(a[i++], a[len_a - 1 - i]);
  i = 0;
  while(i < len_b - 1 - i) Swap(b[i++], b[len_b - 1 - i]);
  int result = atoi(a) + atoi(b);
  while(result % 10 == 0) result /= 10;
  while(result)
  {
    std::cout << result % 10;
    result /= 10;
  }
  std::cout << "\n";
}
