#include <stdio.h>
int N,M,x,max,sum;
int main() {
  scanf("%d%d",&N,&M);
  for(int i=0;i<N;i++) {
    scanf("%d",&x);
    max=x>max?x:max;
  }
  sum+=max,max=0;
  for(int i=0;i<M;i++) {
    scanf("%d",&x);
    max=x>max?x:max;
 }
 printf("%d\n",sum+max);
}
