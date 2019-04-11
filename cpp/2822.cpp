#include <bits/stdc++.h>
template <typename T>
using score = std::pair<T,T>;
int
main() {
  int buf,sum=0;
  std::vector<score<int>> scores;
  std::ios_base::sync_with_stdio(false);
  for(int i=0;i<8;i++) {
    std::cin >> buf;
    scores.push_back(std::make_pair(i+1,buf));
  }
  std::sort(scores.begin(),scores.end(),[](score<int> a,score<int> b)->bool {
      return a.second > b.second;
    });
  while(scores.size() > 5) {
    scores.pop_back();
  }
  for(auto i : scores) {
    sum += i.second;
  }
  std::sort(scores.begin(),scores.end(),[](score<int> a,score<int> b)->bool {
      return a.first < b.first;
    });
  std::cout << sum << "\n";
  for(auto i : scores) {
    std::cout << i.first << " ";
  }
  std::cout << "\n";
}
