#include <iostream>
char s[104];
int n, a, b;
int main()
{
  std::cin >> s;
  std::cin >> n;
  for(int i=0;i<n;++i)
  {
    std::cin >> a >> b;
    char t = s[a];
    s[a] = s[b];
    s[b] = t;
  }
  std::cout << s << "\n";
}
