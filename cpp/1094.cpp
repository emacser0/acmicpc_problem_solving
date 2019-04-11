#include <iostream>
#include <set>
#include <algorithm>
using msint = std::multiset<int>;
using msintitr = std::multiset<int>::iterator;
int
main() {
  int x,sum=0;
  std::multiset<int> sticks;
  auto insert_stick = [&sticks,&sum](int stick) {
    sticks.insert(stick);
    sum+=stick;
  };
  auto remove_first_stick = [&sticks,&sum](){
    sum-=*(sticks.begin());
    sticks.erase(sticks.begin());    
  };
  std::cin >> x;
  insert_stick(64);
  while(sum>x) {
    int curstick=*(sticks.begin());    
    remove_first_stick();
    if((sum+curstick/2)<x) {
      insert_stick(curstick/2);
    }
    insert_stick(curstick/2);    
  }  
  std::cout << sticks.size() << "\n";
}
