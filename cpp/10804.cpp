#include <iostream>
int cards[20], a, b, t;
int main()
{
  for(int i = 0; i < 20; ++i)
  {
    cards[i] = i + 1;
  }
  for(int i = 0; i < 10; ++i)
  {
    std::cin >> a >> b;
    a -= 1, b -= 1;
    while(a < b)
    {
      t = cards[a];
      cards[a] = cards[b];
      cards[b] = t;
      a += 1, b -= 1;
    }
  }
  for(int i = 0; i < 20; ++i)
  {
    std::cout << cards[i] << " ";
  }
  std::cout << "\n";
}
