#include <iostream>
#include <string>
#include <cmath>
long long a,b,c;
int
main() {
  std::ios_base::sync_with_stdio(false);
  std::cin >> a >> b;
  while(b) {
    c=a%b;
    a=b;
    b=c;
  }
  std::cout << std::string(a,'1') << "\n";
}
