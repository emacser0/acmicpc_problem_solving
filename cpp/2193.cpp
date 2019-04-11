#include <iostream>
int n;
long long b[99][2];
int
main() {
  std::cin >> n;
  b[0][0]=0;
  b[0][1]=1;
  for(int i=1;i<n;i++) {
    b[i][0]=b[i-1][0]+b[i-1][1];
    b[i][1]=b[i-1][0];
  }
  std::cout << b[n-1][0]+b[n-1][1] << "\n";
}
// another solution
// long long b[99]
// b[0]=1,b[1]=1;
// int
// main() {
//   std::cin >> n;
//   for(int i=2;i<n;i++) {
//     b[i]=b[i-2]+b[i-1];
//   }
//   std::cout << b[n-1] <<"\n";
// }
