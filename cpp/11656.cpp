#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
std::string str;
std::vector<std::string> prefix;
int
main() {
  std::cin >> str;
  for(int i=str.size()-1;i>=0;i--) {
    prefix.push_back(str.substr(i));
  }
  std::sort(prefix.begin(),prefix.end());
  for(auto i : prefix) {
    std::cout << i << "\n";
  }
}
