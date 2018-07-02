#include <bits/stdc++.h>
int apbc[26];
int
main() {
  std::string buf;
  std::cin >> buf;  
  for(char i : buf) {
    apbc[i-'a']++;
  }
  for(int i : apbc) {
    std::cout << i << " ";
  }
  std::cout << "\n";
}
