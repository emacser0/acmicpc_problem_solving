#include <cstdio>
#include <iostream>
#include <cmath>
long long s, e, sum;
int main()
{
  scanf("%d%d",&s, &e);
  for(int i = 1; i <= e; ++i)
  {
    sum += i;
    if(i >= s && i <= e)
    {
      // printf("sum[%d] = %d, floor(sqrt(2sum)) = %f\n",
      //        i, sum, floor(sqrt(2 * sum)));
      if(floor(sqrt(2*sum)) != i)
      {
        printf("oh... no!!!\n");
        exit(1);
      }
    }
  }
  printf("sum = %lld\n", sum);
}
