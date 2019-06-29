#include <cstdio>
int n;
int getsum(int n)
{
  int sum = 0;
  while(n)
  {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}
int main()
{
  scanf("%d", &n);
  int t = n;
  for(;getsum(t) % 4 != 0; ++t);
  printf("%d\n", t);
}
