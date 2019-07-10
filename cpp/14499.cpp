#include <cstdio>
int n,m,r,c,k,map[24][24],dice[6]={0,0,0,0,0,0},table[4][6]={{1,5,0,3,4,2},{2,0,5,3,4,1},{4,1,2,0,5,3},{3,1,2,5,0,4}},cmd;
int move(int d) {
  if(d>4) return 0;
  int nd[6];
  if(d==1&&c+1<m) c++;
  else if(d==2&&c-1>=0) c--;
  else if(d==3&&r-1>=0) r--;
  else if(d==4&&r+1<n) r++;
  else return 0;
  for(int i=0;i<6;i++)
    nd[i]=dice[table[d-1][i]];
  for(int i=0;i<6;i++)
    dice[i]=nd[i];
  return 1;
}
int
main() {
  scanf("%d%d%d%d%d",&n,&m,&r,&c,&k);
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      scanf("%d",&map[i][j]);
  for(int i=0;i<k;i++) {
    scanf("%d",&cmd);
    if(move(cmd)) {
      printf("%d\n",dice[0]);
      if(map[r][c]) dice[5]=map[r][c],map[r][c]=0;
      else map[r][c]=dice[5];
    }
  }
}
