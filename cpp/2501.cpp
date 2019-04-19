#include <stdio.h>
int N,K,c,r;
int main() {
  scanf("%d%d",&N,&K);
  for(int i=1;i<=N;i++) {
    if(N%i==0) {
      K--;
      if(!K) {
        r=i;
        break;
      }
    }
  }
  printf("%d\n",r);
}
