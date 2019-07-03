#include <iostream>
int n, sum;
char s[104];
int main()
{
  std::cin >> n;
  std::cin >> s;
  for(int i=0;i<n;++i)
  {
    sum += s[i] - 'A' + 1;
  }
  std::cout << sum << "\n";
}
