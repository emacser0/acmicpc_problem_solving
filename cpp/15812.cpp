#include <stdio.h>
#include <math.h>
#define For(x, s, e) for(int x = s; x < e; ++x)
int Max(int a, int b)
{
  return a>b?a:b;
}
int Min(int a, int b)
{
  return a<b?a:b;
}
char map[50][50],ti[500],tj[500];
int n,m,tl,mr,max,min=2e9;
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
  For(i,0,n) {
    For(j,0,m) {
      int t=j+1;
      For(k,i,n) {
        For(l,t,m) {
          max=0;
          if(!map[i][j]&&!map[k][l]) {
            For(m,0,tl) {
              max=Max(max,Min(abs(ti[m]-i)+abs(tj[m]-j),abs(ti[m]-k)+abs(tj[m]-l)));
            }
            min=min<max?min:max;
          }
        }
        t=0;
      }
    }
  }
  printf("%d\n",min);
}
