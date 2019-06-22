#include <cstdio>
#include <cstring>
char buf[50], name[30];
int n,p,c,max;
int main()
{
  scanf("%d",&n);
  for(int i = 0;i < n;++i)
  {
    scanf("%d",&p);
    max = 0;
    for(int j = 0;j < p;++j)
    {
      scanf("%d %s",&c, buf);
      if(c > max)
      {
        max = c;
        strcpy(name, buf);
      }
    }
    printf("%s\n",name);
  }
}
