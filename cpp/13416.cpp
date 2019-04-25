#include <stdio.h>
int max(int a, int b) {
  return a>b?a:b;
}
int T,N,A,B,C,sum;
int main() {
  scanf("%d",&T);
  for(int i=0;i<T;i++) {
    sum=0;
    scanf("%d",&N);
    for(int j=0;j<N;j++) {
      scanf("%d%d%d",&A,&B,&C);
      sum+=max(0,max(max(A,B),C));
    }
    printf("%d\n",sum);
  }
}
