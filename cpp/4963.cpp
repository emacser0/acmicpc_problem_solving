#include <cstdio>
int w,h,m[51][51],q_x[5000],q_y[5000],qi,
  st_x[8]={0,1,0,-1,1,1,-1,-1},st_y[8]={-1,0,1,0,-1,1,1,-1},c;
void
dfs(int y,int x) {
  int nx,ny;
  if(m[y][x]!=2) {
    m[y][x]=2;
    for(int i=0;i<8;i++) {
      nx=x+st_x[i],ny=y+st_y[i];
      if(ny>=0&&ny<h&&nx>=0&&nx<w&&m[ny][nx]==1) {
        dfs(ny,nx);
      }
    }
  }
}
int
main() {
  for(;;) {
    scanf("%d%d",&w,&h);
    if(!w&&!h) {
      break;
    }
    for(int i=0;i<h;i++) {
      for(int j=0;j<w;j++) {
        scanf("%d",&m[i][j]);
        if(m[i][j]) {
          q_y[qi]=i;
          q_x[qi++]=j;
        }
      }
    }
    for(int i=0;i<qi;i++) {
      if(m[q_y[i]][q_x[i]]!=2) {
        dfs(q_y[i],q_x[i]);
        c++;
      }
    }
    printf("%d\n",c);
    c=0,qi=0;
  }
}
