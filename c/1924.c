#include <stdio.h>
char ms[7][4]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
int i,j,m,x,y,t;

int
main() {
  for(scanf("%d %d",&x,&y);i<x;i++) {
    for(j=0;j<(t=(i%2==0&&i<7)|(i%2==1&&i>6)?31:i==1?28:30);j++) {
      m=i==x-1&&j==y-1?puts(ms[m]):m==6?0:m+1;
    }
  }      
}
