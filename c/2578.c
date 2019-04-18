#include <stdio.h>
int board[5][5],bingo[5][5],pos[25][2],n,x,y;
int chk() {
  int r=0,f=1;
  for(int i=0;i<5;i++) {
    f=1;
    for(int j=0;j<5;j++) {
      if(!bingo[i][j]){f=0;break;}
    }
    if(f)r+=1;
  }
  for(int i=0;i<5;i++) {
    f=1;
    for(int j=0;j<5;j++) {
      if(!bingo[j][i]){f=0;break;}
    }
    if(f)r+=1;
  }
  f=1;
  for(int i=0;i<5;i++) {
    if(!bingo[i][i]){f=0;break;}
  }
  if(f)r+=1;
  f=1;
  for(int i=0;i<5;i++) {
    if(!bingo[i][4-i]){f=0;break;}
  }
  if(f)r+=1;
  return r;
}
int
main() {
  for(int i=0;i<5;i++) {
    for(int j=0;j<5;j++) {
      scanf("%d",&board[i][j]);
      pos[board[i][j]][0]=i;
      pos[board[i][j]][1]=j;
    }
  }
  for(int i=0;i<25;i++) {
    scanf("%d",&n);
    bingo[pos[n][0]][pos[n][1]]=1;
    if(i>10&&chk()>=3){
      printf("%d\n",i+1);
      break;
    }
  }
}
