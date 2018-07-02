#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <functional>
int
main() {
  int n;
  std::string buf;
  std::unordered_set<std::string> words;
  std::cin >> n;
  auto compare=[](std::string a,std::string b)->bool {
    if(a.size()==b.size()) {
      return a.compare(b)<0;
    }
    else {
      return a.size()<b.size();
    }
  };
  for(int i=0;i<n;i++) {
    std::cin >> buf;
    words.insert(buf);
  }
  std::vector<std::string> sorted;
  std::copy(words.begin(),words.end(),std::back_inserter(sorted));
  std::sort(sorted.begin(),sorted.end(),compare);
  std::for_each(sorted.begin(),sorted.end(),[](std::string i) {
      std::cout << i <<"\n";
    });
}
