#include <stdio.h>
#include <math.h>
int _max(int a, int b){
  return a>b?a:b;
}
int _min(int a, int b){
  return a<b?a:b;
}
char map[50][50],ti[500],tj[500];
int n,m,tl,mr,mmax,min=2e9;
int main() {
  scanf("%d%d",&n,&m);
  for(int i=0;i<n;i++) {
    scanf("%s",map[i]);
    for(int j=0;j<m;j++) {
      map[i][j]-='0';
      if(map[i][j]) {
        ti[tl]=i;
        tj[tl++]=j;
      }
    }
  }
  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      int t=j+1;
      for(int k=i;k<n;k++) {
        for(int l=t;l<m;l++) {
          mmax=0;
          if(!map[i][j]&&!map[k][l]) {
            for(int m=0;m<tl;m++) {
              mmax=_max(mmax,_min(abs(ti[m]-i)+abs(tj[m]-j),abs(ti[m]-k)+abs(tj[m]-l)));
            }
            min=min<mmax?min:mmax;
          }
        }
        t=0;
      }
    }
  }
  printf("%d\n",min);
}
