#include <iostream>
#include <cstring>
int hlen, nlen, cnt;
char H[100004], N[14];
int main()
{
  std::cin >> H >> N;
  hlen = strlen(H), nlen = strlen(N);
  for(int i = 0; i < hlen; ++i)
  {
    if(strncmp(H + i, N, nlen) == 0)
    {
      cnt += 1;
    }
  }
  std::cout << cnt << "\n";
}
