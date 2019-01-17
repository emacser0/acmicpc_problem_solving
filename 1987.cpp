#include <cstdio>
int r,c,dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int va[26];
char map[24][24];
int dfs(int x, int y, int cnt) {  
  va[map[y][x]-'A']=1;  
  int nx,ny,value,max=cnt;
  for(int i=0;i<4;i++) {
    nx=x+dx[i],ny=y+dy[i];
    if(nx>=0&&nx<c&&ny>=0&&ny<r&&(!va[map[ny][nx]-'A'])) {
      value=dfs(nx,ny,cnt+1);
      max=max>value?max:value;
    }    
  }  
  va[map[y][x]-'A']=0;
  return max;
}
int
main() {
  scanf("%d%d",&r,&c);
  for(int i=0;i<r;i++) {
    scanf("%s",map[i]);
  }
  printf("%d\n",dfs(0,0,1));
}
