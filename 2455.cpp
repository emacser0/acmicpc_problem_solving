#include <bits/stdc++.h>
int
main() {
  std::ios_base::sync_with_stdio(false);
  int in,out,train=0,max=0;
  for(int i=0;i<4;i++) {
    std::cin >> out >> in;
    train+=in-out;
    max=train>max?train:max;
  }
  std::cout << max << "\n";
}
