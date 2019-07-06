#include <iostream>
int t, n, wb, bw, cnt;
char a[100004], b[100004];
int main()
{
  std::cin >> t;
  for(int i = 0; i < t; ++i)
  {
    wb = bw = cnt = 0;
    std::cin >> n >> a >> b;
    for(int j = 0; j < n; ++j)
    {
      if(a[j]=='W'&&b[j]=='B')
      {
        wb += 1;
      }
      else if(a[j]=='B'&&b[j]=='W')
      {
        bw += 1;
      }
    }
    std::cout << wb + bw - (wb < bw ? wb : bw) << "\n";
  }
}
