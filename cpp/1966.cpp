#include <iostream>
#include <tuple>
#include <deque>
#include <algorithm>
int
main() {
  int tc,n,m,dp,cnt=1;
  std::pair<int,int> curdoc;
  std::deque<std::pair<int,int>> pqueue;
  std::ios_base::sync_with_stdio(false);
  std::cin >> tc;
  auto check = [&]()->bool {
    for(auto pi : pqueue) {
      if(curdoc.first<pi.first) {        
        return 1;
      }
    }
    return 0;
  };
  for(int i=0;i<tc;i++) {
    std::cin >> n >> m;
    for(int j=0;j<n;j++) {
      std::cin >> dp;
      pqueue.push_back(std::make_pair(dp,j));
    }
    for(;;) {
      curdoc=pqueue.front();
      pqueue.pop_front();
      if(check()) {
        pqueue.push_back(curdoc);
      }
      else {
        if(curdoc.second==m) {
          break;
        }
        cnt++;
      }      
    }
    std::cout << cnt << "\n";
    cnt=1;
    pqueue = std::deque<std::pair<int,int>>();
  }
}
