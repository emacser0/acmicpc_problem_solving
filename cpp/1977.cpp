#include <iostream>
#include <cmath>
int m,n;
int
main() {
  std::cin >> m >> n;
  if((int)(sqrt(m))==(int)(sqrt(n))) {
    std::cout << -1 << "\n";
    return 0;
  }
  int min=pow(ceil(sqrt(m)),2);
  int sum=min;
  for(int i=ceil(sqrt(m))+1;i<=(int)(sqrt(n));i++) {
    sum+=i*i;
  }
  std::cout << sum << "\n" << min <<"\n";
}
