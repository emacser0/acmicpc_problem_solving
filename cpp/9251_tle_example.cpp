#include <iostream>
#include <cstring>
char sa[1004], sb[1004];
int len_a, len_b;
int Max(int a,  int b)
{
  return a > b ? a : b;
}
int Min(int a, int b)
{
  return a < b ? a : b;
}
int count(int is, int js)
{
  int max = 0;
  for(int i = is; i < len_a; ++i)
  {
    for(int j = js; j < len_b; ++i)
    {
      if(sa[i] == sb[j])
      {
        max = Max(max, count(i + 1, j + 1) + 1);
      }
    }
  }
}
int main()
{
  std::cin >> sa >> sb;
  len_a = strlen(sa) , len_b = strlen(sb);
  std::cout << count(0, 0);
}
