#include <iostream>
#include <iomanip>
#include <cmath>
double L;
int main()
{
  std::cin >> L;
  std::cout << std::setprecision(15) << sqrt(3) * L * L / 4;
}
