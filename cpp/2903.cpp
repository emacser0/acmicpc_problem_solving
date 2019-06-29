#include <iostream>
#include <cmath>
#define ll long long
ll n;
int main()
{
  std::cin >> n;
  ll r = 1 + powl(2, n);
  std::cout << r * r << "\n";
}
