#include <iostream>
long long int q, k, n, a, b;
int main()
{
  scanf("%d", &q);
  for(int i=0;i<q;++i)
  {
    std::cin >> k >> n >> a >> b;
    long long cnt = 0;
    if(b * n >= k)
    {
      std::cout << -1 << "\n";
      continue;
    }
    long long s = 0, e = n;
    while(s <= e)
    {
      long long mid = (s + e) / 2;
      long long r = a * mid + b * (n - mid);
      if(r < k)
      {
        s = mid + 1;
      }
      else
      {
        e = mid - 1;
      }
    }
    std::cout << e << "\n";
  }
}
