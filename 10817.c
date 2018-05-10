#include <stdio.h>
int i,xs[3],t1,t2;

int
main() {
  for(scanf("%d %d %d",&xs[0],&xs[1],&xs[2]);i<3;i++) {
    t1=i==0?1:0;
    t2=i==2?1:2;
    i=!(xs[t1]<xs[i]||xs[t2]>xs[i])||!(xs[t1]>xs[i]||xs[t2]<xs[i])?printf("%d\n",xs[i])+3:i;
  }
}
