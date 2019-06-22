#include <cstdio>
int a,b,x,y;
int main()
{
  for(int i=0;i<3;++i)
  {
    scanf("%d%d",&a,&b);
    x^=a,y^=b;
  }
  printf("%d %d\n",x, y);
}
