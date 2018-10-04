#include <iostream>
long n,c[100],d[101][21];
int
main() {
  std::cin >> n;
  for(int i=0;i<n;i++) {
    std::cin >> c[i];
  }
  d[0][c[0]]=1;
  for(int i=0;i<n;i++) {
    for(int j=0;j<21;j++) {
      if(j+c[i+1]<21) {
        d[i+1][j+c[i+1]]+=d[i][j];
      }
      if(j-c[i+1]>-1) {
        d[i+1][j-c[i+1]]+=d[i][j];
      }
    }
  }
  std::cout << d[n-2][c[n-1]] << "\n";
}
