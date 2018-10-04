#include <iostream>
int T,n,s,dp[12][12];
int
main() {
  std::cin >> T;
  for(int t=0;t<T;t++) {
    std::cin >> n;
    s=0;
    dp[0][1]=1,dp[0][2]=1,dp[0][3]=1;
    for(int i=1;i<n;i++) {
      for(int j=1;j<n+1;j++) {
        for(int k=1;k<4;k++) {
          if(j+k<=n) {
            dp[i][j+k]+=dp[i-1][j];
          }
        }
      }
    }
    for(int i=0;i<n+1;i++) {
      for(int j=0;j<n+1;j++) {
        if(j==n) {
          s+=dp[i][j];
        }
        dp[i][j]=0;
      }
    }
    std::cout << s << "\n";
  }
}
