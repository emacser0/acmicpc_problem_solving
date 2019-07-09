#include <cstdio>
#include <cmath>
#include <cstring>
int N, M, t, ocnt[10], ncnt[10], cnt;
int main()
{
  scanf("%d%d", &N, &M);
  for(int i = 0; i < M; ++i)
  {
    scanf("%d", &t);
    ocnt[t] = 1;
  }
  int end = pow(10, N);
  for(int i = 0; i < end; ++i)
  {
    for(int j = 0, t = i; j < N; ++j)
    {
      if(ocnt[t % 10]) ncnt[t % 10] = 1;
      t /= 10;
    }
    if(memcmp(ocnt, ncnt, sizeof(ocnt)) == 0) cnt += 1;
    memset(ncnt, 0, sizeof(ncnt));
  }
  printf("%d\n", cnt);
}
