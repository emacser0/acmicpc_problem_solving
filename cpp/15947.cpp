#include <iostream>
#include <string>
int n;
std::string lyrics[8] = {"baby", "sukhwan", "turu", "tu", "very", "cute", "in", "bed"};
int pointers[14] = {0, 1, 2, 3, 4, 5, 2, 3, 6, 7, 2, 3, 0, 1};
const std::string& find_lyric(int p)
{
  return lyrics[pointers[p]];
}
void print_word(int n, int p)
{
  bool a = find_lyric(p) == "turu", b = find_lyric(p) == "tu";
  std::cout << (a ? "tu" : find_lyric(p));
  if(a || b)
  {
    if(n >= (a ? 4 : 5)) std::cout << "+ru*" <<  n + (a ? 1 : 0);
    else
    {
      if(a) std::cout << "ru";
      for(int i = 0; i < n; ++i)
      {
        std::cout << "ru";
      }
    }
  }
  std::cout << "\n";
}
int main()
{
  std::cin >> n;
  print_word(n / 14 + 1, (n - 1) % 14);
}
