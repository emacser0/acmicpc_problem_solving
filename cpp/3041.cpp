#include <iostream>
#include <cmath>
int sum = 0;
char s[5];
int main()
{
  for(int i = 0; i < 4; ++i)
  {
    std::cin >> s;
    for(int j = 0; j < 4; ++j)
      if(s[j] != '.') sum += abs((s[j] - 'A') / 4 - i) + abs((s[j] - 'A') % 4 - j);
  }
  std::cout << sum << "\n";
}
