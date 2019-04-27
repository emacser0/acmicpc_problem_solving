#include <stdio.h>
int T,N,x,max,max2flag,mi,sum;
int main() {
  scanf("%d",&T);
  for(int i=0;i<T;i++) {
    scanf("%d",&N);
    sum=0,max=0,max2flag=0,mi=0;
    for(int j=0;j<N;j++) {
      scanf("%d",&x);
      sum+=x;
      if(x>max) {
        max=x,max2flag=0,mi=j;
      }
      else if(x==max) max2flag=1;
    }
    if(max2flag) puts("no winner");
    else printf("%s winner %d\n",max>sum/2?"majority":"minority",mi+1);
  }
}
