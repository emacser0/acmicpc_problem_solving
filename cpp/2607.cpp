#include <iostream>
#include <cstring>
#include <cmath>
int N, ocnt[30], ncnt[30];
char s[14];
int main()
{
  std::cin >> N >> s;
  int olen = strlen(s);
  for(int i = 0; i < olen; ++i)
  {
    ocnt[s[i] - 'A'] += 1;
  }
  int cnt = 0;
  for(int i = 0; i < N - 1; ++i)
  {
    std::cin >> s;
    int len = strlen(s), diff = 0, swap_flag = 0;
    for(int j = 0; j < len; ++j)
    {
      ncnt[s[j] - 'A'] += 1;
    }
    for(int j = 0; j < 26; ++j)
    {
      if(ocnt[j] != ncnt[j])
      {
        diff += abs(ocnt[j] - ncnt[j]);
      }
    }
    if(olen != len && diff <=  1) cnt += 1;
    else if(olen == len && diff <= 2) cnt += 1;
    memset(ncnt, 0, sizeof(ncnt));
  }
  std::cout << cnt << "\n";
}
