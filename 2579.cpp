#include <iostream>
#include <deque>
int n,max,score[302],dp[2250000][2];
void go(int i, int c,int sum) {
  if(i<2) {
    go(i+1,c+1,sum+score[i]);
  }

}
int
main() {
  std::cin >> n;
  for(int i=0;i<n;i++) {
    std::cin >> score[i];
    max=score[i]>max?score[i]:max;
  }
  for(int i=0;i<max*n;i++) {
    dp[i][1]=-1;
  }
  dp[score[0]][0]=1,dp[score[0]][1]=0;
  dp[score[1]][0]=1,dp[score[1]][1]=1;
  for(int i=1;i<n+1;i++) {
    for(int j=1;j<max*i;j++) {
      if(dp[j][1]!=0 and (dp[j][1]==i-1 or dp[j][1]==i-2)) {
        if(dp[j][0]<3) {
          dp[j+score[i]][0]=dp[j][0]+1;
          dp[j+score[i]][1]=i;
        }
        if(i<n) {
          dp[j+score[i+1]][0]=1;
          dp[j+score[i+1]][1]=i+1;
        }
      }
    }
  }
  for(int i=max*n;i>0;i--) {
    if(dp[i][1]==n-1) {
      std::cout << i << "\n";
      break;
    }
  }
}
