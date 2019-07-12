#include <iostream>
#include <cstring>
int values[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
int sum;
char a[20], b[20];
char symbols[13][3] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
int calculate(char *s, int len)
{
  int sum = 0;
  for(int i = 0; i < len; ++i)
  {
    for(int j = 0; j < 13; ++j)
    {
      if(strncmp(s + i, symbols[j], j % 2 + 1) == 0)
      {
        sum += values[j];
        i += j % 2;
        break;
      }
    }
  }
  return sum;
}
int main()
{
  std::cin >> a >> b;
  int len_a = strlen(a), len_b = strlen(b);
  int sum = calculate(a, len_a) + calculate(b, len_b);
  std::cout << sum << "\n";
  int cnt = 0;
  for(int i = 0; i < 13; ++i)
  {
    if(i % 2 > 1)
    {
      sum -= values[i];
      std::cout << symbols[i];
      continue;
    }
    while(sum >= values[i])
    {
      sum -= values[i];
      std::cout << symbols[i];
    }
  }
}
