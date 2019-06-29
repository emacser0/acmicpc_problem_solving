#include <cstdio>
#include <algorithm>
#include <functional>
#include <set>
int q, n, t, cnt[200001];
int main()
{
  scanf("%d",&q);
  for(int i=0;i<q;++i)
  {
    scanf("%d",&n);
    std::fill(cnt, cnt+n, 0);
    for(int j=0;j<n;++j)
    {
      scanf("%d",&t);
      cnt[t-1] += 1;
    }
    std::sort(cnt, cnt + n, std::greater<int>());
    int max = cnt[0];
    int c = max;
    for(int j=1; j<n; j++)
    {
      max--;
      if(cnt[j] < max) max = cnt[j];
      if(max <= 0) break;
      c += max;
    }
    printf("%d\n", c);
  }
}
