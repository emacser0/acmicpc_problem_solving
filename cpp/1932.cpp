#include <iostream>
#include <cmath>
int n,tri[501][501];
int
main() {
  std::ios_base::sync_with_stdio(false);
  std::cin >> n;
  for(int i=0;i<n;i++) {
    for(int j=0;j<=i;j++) {
      std::cin >> tri[i][j];
    }
  }
  for(int i=1;i<n;i++) {
    for(int j=i;j>0;j--) {
      tri[i][j]+=std::max(tri[i-1][j],tri[i-1][j-1]);
    }
    tri[i][0]+=tri[i-1][0];
  }
  int max=0;
  for(int i=0;i<n;i++) {
    max=std::max(max,tri[n-1][i]);
  }
  std::cout << max << "\n";
  // reverse soulution (without calculating max)
  // for(int i=n-2;i>=0;i--) {
  //   for(int j=0;j<=i;j++) {
  //     tri[i][j]+=std::max(tri[i+1][j],tri[i+1][j+1]);
  //   }
  // }
  // std::cout << tri[0][0];
}
