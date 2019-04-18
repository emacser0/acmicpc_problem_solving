#include <stdio.h>
int max(int a,int b){return a>b?a:b;}
int map[150][150],x1,y1,x2,y2,mx,my,c;
int main() {
  for(int i=0;i<4;i++) {
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    mx=max(mx,max(x1,x2));
    my=max(my,max(y1,y2));
    for(int i=y1+1;i<=y2;i++) {
      for(int j=x1+1;j<=x2;j++) {
        map[i][j]=1;
      }
    }
  }
  for(int i=1;i<=my;i++) {
    for(int j=1;j<=mx;j++) {
      if(map[i][j])c++;
    }
  }
  printf("%d\n",c);
}
