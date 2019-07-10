#include <cstdio>
#include <cstring>
#include <cmath>
char color[10][9]={"black","brown","red","orange","yellow","green","blue","violet","grey","white"},buf[9];
long long result;
int
main()
{
  for(int i=0;i<2;i++)
  {
    scanf("%s",buf);
    for(int j=0;j<10;j++)
    {
      if(!strcmp(buf,color[j]))
      {
        result += j*pow(10,1-i);
        break;
      }
    }
  }
  scanf("%s",buf);
  for(int i=0;i<10;i++)
  {
    if(!strcmp(buf,color[i]))
    {
      result*=powl(10,i);
      break;
    }
  }
  printf("%lld\n",result);
}
