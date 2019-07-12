#include <iostream>
int N, max, a, b, c;
int Max(int a, int b) { return a > b ? a : b; }
int main()
{
  std::cin >> N;
  for(int i = 0; i < N; ++i)
  {
    int score = 0;
    std::cin >> a >> b >> c;
    if(a == b && b == c) score = 10000 + a * 1000;
    else if(a == b) score = 1000 + a * 100;
    else if(b == c) score = 1000 + b * 100;
    else if(c == a) score = 1000 + c * 100;
    // shorter expression of 12 - 14
    // else if(a == b || b == c) score = 1000 + b * 100;
    // else if(c == a) score = 1000 + a * 100;
    else score = Max(a, Max(b, c)) * 100;
    max = Max(max, score);
  }
  std::cout << max;
}
