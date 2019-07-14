#include <iostream>
double A, B, C, D, max;
int maxi;
int main()
{
  std::cin >> A >> B >> C >> D;
  max = A/C+B/D;
  if(C/D+A/B > max) max = C/D+A/B, maxi = 1;
  if(D/B+C/A > max) max = D/B+C/A, maxi = 2;
  if(B/A+D/C > max) max = B/A+D/C, maxi = 3;
  std::cout << maxi << "\n";
}
