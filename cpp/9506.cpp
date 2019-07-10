#include <cstdio>
int n,sum,stack[5000],si;
int
main()
{
  while(1)
  {
    scanf("%d",&n);
    if(n==-1) break;
    sum=0,si=0;
    for(int i=1;i<=n/2;i++)
    if(!(n%i))
    {
      sum += i;
      stack[si++]=i;
    }
    if(n==sum)
    {
      printf("%d = ",n);
      for(int i=0;i<si;i++)
      {
        printf("%d ",stack[i]);
        if(i<si-1)
        {
          printf("+ ");
        }
      }
      puts("");
    }
    else
    {
      printf("%d is NOT perfect.\n",n);
    }
  }
}
