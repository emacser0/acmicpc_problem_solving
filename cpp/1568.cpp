#include <cstdio>
int n,cnt,t;
int
main()
{
  scanf("%d",&n);
  t=n;
  for(int i=1;i<=n&&t>0;i++)
  {
    if(t<i)
    {
      i=0;
      continue;
    }
    t-=i;
    cnt++;
  }
  printf("%d\n",cnt);
}
