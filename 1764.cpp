#include <iostream>
#include <map>
#include <set>
#include <string>
int n,m,cnt;
std::string str;
std::map<std::string,int> names;
std::set<std::string> dsdh;
int
main() {
  std::cin >> n >> m;
  for(int i=0;i<n;i++) {
    std::cin >> str;
    names.insert({str,1});
  }
  for(int j=0;j<m;j++) {
    std::cin >> str;
    if(names[str]) {
      cnt++;
      dsdh.insert(str);
    }
  }
  std::cout << cnt << "\n";
  for(auto i : dsdh) {
    std::cout << i << "\n";
  }
}
