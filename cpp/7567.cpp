#include <iostream>
#include <cstring>
int len, count = 10;
char s[54];
int main()
{
  std::cin >> s;
  len = strlen(s);
  for(int i = 1; i < len; ++i)
  {
    if(s[i] != s[i - 1])
    {
      count += 10;
    }
    else
    {
      count += 5;
    }
  }
  std::cout << count << "\n";
}
