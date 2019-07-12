#include <iostream>
int T, N, cnt;
double M;
int main()
{
  for(scanf("%d", &T); T; --T)
  {
    scanf("%d%lf", &N, &M);
    cnt = 0;
    for(int i = 1; i < N; ++i)
    {
      for(int j = i + 1; j < N; ++j)
      {
        double r = (i*i+j*j+M) / (i * j);
        if(r == (int)r)
        {
          cnt += 1;
        }
      }
    }
    printf("%d\n", cnt);
  }
}
