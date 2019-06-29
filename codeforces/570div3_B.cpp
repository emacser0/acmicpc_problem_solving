#include <cstdio>
#include <cmath>
#include <cstring>
long long int q, n, k, a[1000], r[1000];
int main()
{
  scanf("%d", &q);
  for(int i = 0; i < q; ++i)
  {
    scanf("%d%d", &n, &k);
    int min = 1e9, max = 0;
    memset(a, 0, 999 * sizeof(int));
    memset(r, 0, 999 * sizeof(int));
    for(int j = 0; j < n; ++j)
    {
      scanf("%d", a + j);
      int t = a[j];
      min = min > t ? t : min;
      max = max < t ? t : max;
    }
    int result = min + k;
    if(result < max - k)
    {
      printf("-1\n");
    }
    else
    {
      printf("%d\n",result);
    }
  }
  return 0;
}
