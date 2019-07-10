#include <cstdio>
int r,c,dx[4]={0,1,0,1},dy[4]={0,0,1,1},ablecnt[5];
char map[99][99];
int
main()
{
  scanf("%d%d",&r,&c);
  for(int i=0;i<r;i++) scanf("%s",map[i]);
  for(int i=0;i<r-1;i++)
  {
    for(int j=0;j<c-1;j++)
    {
      int cond=1,cnt=0;
      for(int k=0;k<4;k++)
      {
        char value = map[i+dy[k]][j+dx[k]];
        if(value == '#')
        {
          cond=0;
          break;
        }
        else if(value == 'X') cnt++;
      }
      ablecnt[cnt]+=cond;
    }
  }
  for(int i=0;i<5;i++) printf("%d\n",ablecnt[i]);
}
