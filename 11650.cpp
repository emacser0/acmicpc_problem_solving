#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
template <typename T>
using point = std::pair<T,T>;
int
main() {
  int n;
  std::vector<point<int>> points;
  std::ios_base::sync_with_stdio(false);
  auto compare = [](point<int> a,point<int> b)->bool {
    if(a.first!=b.first) {
      return a.first<b.first;
    }
    else {
      return a.second<b.second;
    }
  };
  std::cin >> n;
  int x,y;
  for(int i=0;i<n;i++) {
    std::cin >> x >> y;
    points.push_back(std::make_pair(x,y));
  }
  std::sort(points.begin(),points.end(),compare);
  std::for_each(points.begin(),points.end(),[](point<int> i) {
      std::cout << i.first << " " << i.second << "\n";
    });
}
