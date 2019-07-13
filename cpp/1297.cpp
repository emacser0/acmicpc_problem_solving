#include <iostream>
#include <cmath>
int C, H, W;
double ratio;
int main()
{
  std::cin >> C >> H >> W;
  ratio = sqrt(C*C / (double)(H*H + W*W));
  std::cout << floor(H * ratio) << " " << floor(W * ratio) << "\n";
}
