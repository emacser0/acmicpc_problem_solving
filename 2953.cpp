#include <iostream>
#include <vector>
#include <algorithm>
int
main() {
  int buf;
  std::vector<int> scores(5);
  for(int i=0;i<5;i++) {
    for(int j=0;j<4;j++) {
      std::cin >> buf;
      *(scores.begin()+i)+=buf;
    }
  }
  auto itr = std::max_element(scores.begin(), scores.end());
  std::cout << std::distance(scores.begin(),itr)+1 << " " << *(itr);    
}
