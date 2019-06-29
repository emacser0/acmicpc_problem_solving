#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <queue>
#include <set>
#include <algorithm>
int n, k, sum;
std::string s;
std::queue<std::string> q;
std::set<std::string> set;
int main()
{
  std::cin >> n >> k >> s;
  q.push(s);
  set.insert(s);
  while(!q.empty() && set.size() < k)
  {
    std::string ns = q.front();
    q.pop();
    for(int i = 0; i < ns.size() && set.size() < k; ++i)
    {
      std::string rs = ns.substr(0, i) + ns.substr(i + 1);
      if(set.find(rs) == set.end())
      {
        q.push(rs);
        set.insert(rs);
        sum += n - rs.size();
      }
    }
  }
  std::cout << (set.size() >= k ? sum : -1) << "\n";
}
