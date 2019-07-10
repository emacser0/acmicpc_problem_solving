#include <stdio.h>
long long A,B,C;
int main()
{
  scanf("%d%d%d",&A,&B,&C);
  printf("%lld\n",C-B>0?A/(C-B)+1:-1);
}
