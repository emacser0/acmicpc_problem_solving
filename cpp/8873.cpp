#include <iostream>
int H, W;
int R[504][504], G[504][504], B[504][504], rsum, gsum, bsum, red, green, blue, yellow, cyan, magenta, black, white;
int main()
{
  std::cin >> H >> W;
  for(int i = 0; i < H; ++i)
  {
    for(int j = 0; j < W; ++j)
    {
      std::cin >> R[i][j];
      rsum += R[i][j];
    }
  }
  for(int i = 0; i < H; ++i)
  {
    for(int j = 0; j < W; ++j)
    {
      std::cin >> G[i][j];
      gsum += G[i][j];
    }
  }
  for(int i = 0; i < H; ++i)
  {
    for(int j = 0; j < W; ++j)
    {
      std::cin >> B[i][j];
      bsum += B[i][j];
    }
  }
    for(int i = 0; i < H; ++i)
  {
    for(int j = 0; j < W; ++j)
    {
      if(R[i][j] - B[i][j] >= 30)
      {
        if(R[i][j] - G[i][j] >= 30) red += 1;
        else yellow += 1;
      }
      else if(G[i][j] - R[i][j] >= 30)
      {
        if(G[i][j] - B[i][j] >= 30) green += 1;
        else cyan += 1;
      }
      else if(B[i][j] - G[i][j] >= 30)
      {
        if(B[i][j] - R[i][j] >= 30) blue += 1;
        else magenta += 1;
      }
      if(R[i][j] <= 30 && G[i][j] <= 30 && B[i][j] <= 30)
      {
        black += 1;
      }
      else if(R[i][j] <= 220 && G[i][j] <= 220 && B[i][j] <= 220)
      {
        white += 1;
      }
    }
  }
  std::cout << rsum << " " << gsum << " " << bsum << "\n";
  std::cout << "red : " << red << " green : " << green << " blue : " << blue << "\n";
  std::cout << "yellow : " << yellow << " magenta : " << magenta << " cyan : " << cyan << "\n";
  std::cout << "black : " << black << " white : " << white << "\n";
}
