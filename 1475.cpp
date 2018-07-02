#include <bits/stdc++.h>
int count[9],max,tmp;
int
main() {
  std::string buf;
  std::ios_base::sync_with_stdio(false);
  std::cin >> buf;
  for(char i : buf) {
    if(i=='9') {
      count[6]++;
    }
    else {
      count[i-'0']++;
    }
  }
  for(int i=0;i<9;i++) {
    if(i==6) {
      tmp=count[i]/2+count[i]%2;
      max=tmp>max?tmp:max;
    }
    else {
      max=count[i]>max?count[i]:max;
    }
  }
  std::cout << max << "\n";                      
}
