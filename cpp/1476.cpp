#include <cstdio>
int e,s,m,i,a,b,c;
int
main()
{
  scanf("%d%d%d",&e,&s,&m);
  for(;a!=e-1||b!=s-1||c!=m-1;i++)
  {
    a++,b++,c++;
    if(a>14) a=0;
    if(b>27) b=0;
    if(c>18) c=0;
  }
  printf("%d\n",i+1);
}
