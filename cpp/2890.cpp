#include <cstdio>
int r,c,score[9],grade[9];
char buf[54];
int
main()
{
  scanf("%d%d",&r,&c);
  for(int i=0;i<r;i++)
  {
    scanf("%s",buf);
    for(int i=1;i<c-1;i++)
    {
      if(buf[i]!='.')
      {
        score[buf[i]-'1']=c-i;
        break;
      }
    }
  }
  for(int i=0;i<9;i++)
  {
    int cnt=1,v[54]={0,};
    for(int j=0;j<9;j++)
    {
      if(i==j) continue;
      if(score[i]>score[j]&&!v[score[j]]) cnt++,v[score[j]]=1;
    }
    grade[i]=cnt;
  }
  for(int i=0;i<9;i++)
  {
    printf("%d\n",grade[i]);
  }
}
