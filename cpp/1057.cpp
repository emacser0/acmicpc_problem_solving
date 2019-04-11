#include <iostream>
#include <deque>
using dqint = std::deque<int>;
int
main() {
  int n,kn,in,round=1,cur=0;
  dqint players;
  dqint next;
  std::cin >> n >> kn >> in;
  for(int i=1;i<=n;i++) {
    players.push_back(i);
  }
  while(players.size()>1) {    
    for(dqint::iterator i=players.begin();i!=players.end();i++) {
      if(cur==0) {
        cur=*(i);
        if(i==--players.end()) {
          next.push_back(*(i));
          cur=0;
        }        
      }      
      else {      
        if((cur==kn&&*(i)==in)||(cur==in&&*(i)==kn)) {
          std::cout << round << "\n";
          return 0;
        }
        else if(*(i)==in||*(i)==kn){
          next.push_back(*(i));
        }
        else {
          next.push_back(cur);
        }
        cur=0;
      }
    }    
    players=next;
    next=dqint();
    round++;    
  }
}
