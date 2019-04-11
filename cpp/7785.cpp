#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <functional>

int
main() {
  int n;
  std::string name, act;
  std::set<std::string> office;
  std::ios_base::sync_with_stdio(false);
  std::cin >> n;
  std::function<void (int)> loop = [&](int i) {
    if(i<n) {
      std::cin >> name >> act;
      if(!act.compare("enter")) {
        office.insert(name);
      }
      else {
        office.erase(office.find(name));
      }
      loop(i+1);
    }
  };
  loop(0);
  std::for_each(office.rbegin(), office.rend(), [](std::string i) {
      std::cout << i << "\n";
    });
}
