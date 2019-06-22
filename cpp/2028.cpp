#include <cstdio>
int T, n;
int is_self_clone(int n)
{
  int p = n*n;
  while(n)
  {
    if(n%10 != p%10)
    {
      return false;
    }
    n/=10,p/=10;
  }
  return true;
}
int main()
{
  scanf("%d",&T);
  for(int i=0;i<T;++i)
  {
    scanf("%d",&n);
    printf("%s\n",is_self_clone(n)?"YES":"NO");
  }
}
