#include <stdio.h>
int N,M,matrix[104][104],a,b,cnt;
void init() {
  for(int i=0;i<104;i++) {
    for(int j=0;j<104;j++) {
      matrix[i][j]=0;
    }
  }
}
int main() {
  init();
  scanf("%d%d",&N,&M);
  for(int i=0;i<M;i++) {
    scanf("%d%d",&a,&b);
    matrix[a-1][b-1]=1;
  }
  for(int i=0;i<N;i++) {
    for(int j=0;j<N;j++) {
      if(matrix[j][i]) {
        for(int k=0;k<N;k++) {
          matrix[j][k]=matrix[i][k]?1:matrix[j][k];
        }
      }
    }
  }
  for(int i=0;i<N;i++) {
    cnt=0;
    for(int j=0;j<N;j++) {
      if(i!=j&&!(matrix[i][j]|matrix[j][i])) {
        cnt++;
      }
    }
    printf("%d\n",cnt);
  }
}
