#include <stdio.h>
int T,N,M;
int main() {
  scanf("%d",&T);
  for(int i=0;i<T;i++) {
    scanf("%d%d",&N,&M);
    printf("%d %d\n",2*M-N,N-M);
  }
}
