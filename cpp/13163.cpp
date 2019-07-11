#include <iostream>
#include <cstring>
int N;
char s[104];
int main()
{
  std::cin >> N;
  std::cin.ignore();
  for(int i = 0; i < N; ++i)
  {
    std::cin.getline(s, 101);
    int len = strlen(s);
    int si = 0;
    while(s[si++] != ' ');
    for(int i = si; i < len; ++i)
    {
      if(s[i] == ' ')
      {
        for(int j = i + 1; j < len; ++j)
        {
          s[j - 1] = s[j];
        }
        s[len - 1] = '\0';
      }
    }
    std::cout << "god" << s + si << "\n";
  }
}
