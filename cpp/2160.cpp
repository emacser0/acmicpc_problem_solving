#include <iostream>
#include <cstring>
int N;
char pictures[50][5][7];
int diff[50][50];
int main()
{
  std::cin >> N;
  for(int i = 0; i < N; ++i)
    for(int j = 0; j < 5; ++j)
      std::cin >> pictures[i][j];
  int min = 2e9, min_idx[2];
  for(int i = 0; i < N; ++i)
  {
    for(int j = 0; j < N; ++j)
    {
      for(int k = 0; k < 5; ++k)
        for(int l = 0; l < 7; ++l)
          if(pictures[i][k][l] != pictures[j][k][l])
            diff[i][j] += 1;
      if(i != j && diff[i][j] < min)
        min = diff[i][j], min_idx[0] = i, min_idx[1] = j;
    }
  }
  std::cout << min_idx[0] + 1 << " " << min_idx[1] + 1 << "\n";
}
