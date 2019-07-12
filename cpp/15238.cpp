#include <iostream>
int N, cnt[26];
char s[1004];
int main()
{
  std::cin >> N >> s;
  for(int i = 0; i < N; ++i)
  {
    cnt[s[i] - 'a'] += 1;
  }
  int max = 0;
  char maxc = 'a';
  for(int i = 0; i < 26; ++i)
  {
    if(cnt[i] > max)
    {
      max = cnt[i];
      maxc = 'a' + i;
    }
  }
  std::cout << maxc << " " << max << "\n";
}
