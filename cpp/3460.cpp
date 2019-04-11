#include <bits/stdc++.h>
int
main() {
  int n,buf,cnt=0;
  std::cin >> n;
  for(int i=0;i<n;i++) {
    for(std::cin>>buf;buf>0;buf>>=1,cnt++) {
      if(buf&1) {
        std::cout << cnt << " ";
      }
    }
    std::cout << "\n";
    cnt=0;
  }
}
