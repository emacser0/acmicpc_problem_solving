#include <stdio.h>
int N,M,matrix[104][104],a,b,sum,min=2e9,mi;
int _min(int a, int b){return a<b?a:b;}
void init() {
  for(int i=0;i<104;i++) {
    for(int j=0;j<104;j++) {
      matrix[i][j]=1e9;
    }
  }
}
int main() {
  init();
  scanf("%d%d",&N,&M);
  for(int i=0;i<M;i++) {
    scanf("%d%d",&a,&b);
    matrix[a-1][b-1]=1;
    matrix[b-1][a-1]=1;
  }
  for(int i=0;i<N;i++) {
    for(int j=0;j<N;j++) {
      for(int k=0;k<N;k++) {
          matrix[j][k]=_min(matrix[j][k],_min(matrix[j][i]+matrix[i][k],1e9));
      }
    }
  }
  for(int i=0;i<N;i++) {
    sum=0;
    for(int j=0;j<N;j++) {
      if(i!=j&&matrix[i][j]<1e9) sum+=matrix[i][j];
    }
    if(sum<min) {
      min=sum,mi=i;
    }
  }
  printf("%d\n",mi+1);
}
