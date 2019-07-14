#include <iostream>
#include <cstdlib>
#include <cstring>
char s[104];
int main()
{
  while(1)
  {
    std::cin >> s;
    if(strcmp(s, "ENDOFINPUT") == 0) break;
    std::cin.ignore();
    std::cin.getline(s, 101);
    int len = strlen(s);
    for(int i = 0; i < len; ++i)
      if(isupper(s[i])) s[i] = (s[i] - 'A' + 21) % 26 + 'A';
    std::cout << s << "\n";
    std::cin >> s;
  }
}
