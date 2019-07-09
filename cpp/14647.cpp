#include <cstdio>
int n, m, grid[504][504], rsum[504], csum[504];
int Max(int a, int b)
{
  return a > b ? a : b;
}
int get_nine_count(int n)
{
  int cnt = 0;
  while(n)
  {
    if(n - (n / 10) * 10  == 9) cnt += 1;
    n /= 10;
  }
  return cnt;
}
int main()
{
  scanf("%d%d", &n, &m);
  int max = 0, sum = 0;
  for(int i = 0; i < n; ++i)
  {
    int cnt = 0;
    for(int j = 0; j < m; ++j)
    {
      scanf("%d", grid[i] + j);
      int c = get_nine_count(grid[i][j]);
      sum += c;
      rsum[j] += c;
      csum[i] += c;
      if(i==n-1) max = Max(max, rsum[j]);
    }
    max = Max(max, csum[i]);
  }
  printf("%d\n", sum - max);
}
