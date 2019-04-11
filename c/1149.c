#include <stdio.h>
int prices[1000][3];
int mins[1000][3];
int getmin(int xs[3], int e) {
  return e==0?xs[1]<xs[2]?xs[1]:xs[2]:e==1?xs[0]<xs[2]?xs[0]:xs[2]:xs[0]<xs[1]?xs[0]:xs[1];
}
int getmin2(int xs[3]) {
  return xs[0]<xs[1]?xs[0]<xs[2]?xs[0]:xs[2]:xs[1]<xs[2]?xs[1]:xs[2];
}
void
inputmins(int x, int end) {
  if(x==end) {
    for(int i=0;i<3;i++) {
      mins[x][i]=prices[x][i];
    }
  }
  else {
    for(int i=0;i<3;i++) {
      mins[x][i]=prices[x][i]+getmin(mins[x+1],i);
    }
  }
  if(x!=0) {
    inputmins(x-1,end);
  }
}
int
main() {
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;i++) {
    for(int j=0;j<3;j++) {
      scanf("%d",&prices[i][j]);
    }
  }
  inputmins(n-1,n-1);
  printf("%d\n",getmin2(mins[0]));
}
