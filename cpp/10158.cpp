#include <iostream>
int W, H, P, Q, T;
int main()
{
  std::cin >> W >> H >> P >> Q >> T;
  P = (P + T) % (2 * W);
  if(P > W) P = 2 * W - P;
  Q = (Q + T) % (2 * H);
  if(Q > H) Q = 2 * H - Q;
  std::cout << P << " " << Q << "\n";
}
