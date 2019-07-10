#include <iostream>
#include <cmath>
int N,n,r,c,cnt,pos,mul;
int main()
{
  scanf("%d%d%d",&N,&r,&c);
  n=powl(2,N),mul=powl(4,N-1);
  do
  {
    pos=0,n/=2;
    if(r/n)
    {
      r-=n;
      pos+=2;
    }
    if(c/n)
    {
      c-=n;
      pos+=1;
    }
    cnt+=mul*pos,mul/=4;
  } while(n!=1);
  printf("%d\n",cnt);
}
