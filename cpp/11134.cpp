#include <cstdio>
int T,N,C;
int main()
{
  scanf("%d",&T);
  for(int i=0;i<T;++i)
  {
    scanf("%d%d",&N,&C);
    printf("%d\n",N/C+(N%C?1:0));
  }
}
