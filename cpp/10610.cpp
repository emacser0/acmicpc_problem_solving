#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
long long sum, cnt[14];
std::string n;
int main()
{
  std::cin >> n;
  for(auto& i : n)
  {
    sum += i - '0';
    cnt[i - '0'] += 1;
  }
  if(cnt[0] == 0 || sum % 3 != 0)
  {
    std::cout << -1 << "\n";
  }
  else
  {
    for(int i = 9; i >= 0; --i)
    {
      while(cnt[i])
      {
        std::cout << i;
        cnt[i] -= 1;
      }
    }
    std::cout << "\n";
  }
}
