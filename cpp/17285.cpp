#include <iostream>
#include <cstring>
int key;
char T[104];
int main()
{
  for(std::cin >> T; (T[0]^key) != 'C'; ++key);
  size_t len = strlen(T);
  for(int i = 0; i < len; ++i) T[i] ^= key;
  std::cout << T << "\n";
}
