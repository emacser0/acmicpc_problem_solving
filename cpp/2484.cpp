#include <iostream>
int N, a, b, c, d, max;
template <typename T>
T Max(T a, T b) { return a > b ? a : b; }
int main()
{
  std::cin >> N;
  for(int i = 0; i < N; ++i)
  {
    std::cin >> a >> b >> c >> d;
    int score = 0, cnt[9] = {0,}, s[4] = {0,}, j = 2;
    ++cnt[a], ++cnt[b], ++cnt[c], ++cnt[d];
    for(int i = 1; i <= 6; ++i)
    {
      if(cnt[i] == 4) s[0] = i;
      if(cnt[i] == 3) s[1] = i;
      if(cnt[i] == 2) s[j++] = i;
    }
    score = Max(a, Max(b, Max(c, d))) * 100;
    if(s[0]) score = 50000 + s[0] * 5000;
    if(s[1]) score = 10000 + s[1] * 1000;
    if(j == 4) score = 2000 + (s[2] + s[3]) * 500;
    if(j == 3) score = 1000 + s[2] * 100;
    max = Max(max, score);
  }
  std::cout << max << "\n";
}
