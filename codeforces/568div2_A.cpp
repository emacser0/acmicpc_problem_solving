#include <cstdio>
int a[3], d, mc[3];
void insert(int n)
{
  for(int i = 0 ; i < 3 ; ++i)
  {
    if(mc[i] > n)
    {
      for(int j = 1 ; j >= i ; --j)
      {
        mc[j + 1] = mc[j];
      }
      mc[i] = n;
      break;
    }
    if(mc[i] == 0)
    {
      mc[i] = n;
      break;
    }
  }
}

int max(int a, int b)
{
  return a > b ? a : b;
}

int main()
{
  scanf("%d%d%d%d",a, a+1, a+2, &d);
  for(int i = 0 ; i < 3 ; ++i)
  {
    insert(a[i]);
  }
  printf("%d\n",max(d-(mc[1]-mc[0]),0) + max(d-(mc[2]-mc[1]),0));
}
