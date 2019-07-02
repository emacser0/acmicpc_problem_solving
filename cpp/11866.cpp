#include <iostream>
#include <deque>
int n, k;
std::deque<int> v;
int main()
{
  std::cin >> n >> k;
  for(int i = 1; i <= n; ++i)
  {
    v.push_back(i);
  }
  std::cout << "<";
  for(int i = k - 1; ; i = (i + k) % n)
  {
    std::cout << v.at(i) << (n-- > 1 ? ", " : "");
    v.erase(v.begin() + i--);
    if(n <= 0) break;
  }
  std::cout << ">\n";
}
