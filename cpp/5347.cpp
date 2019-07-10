#include <stdio.h>
#define ll long long
ll gcd(ll a,ll b)
{
  ll t;
  while(b)
  {
    t=a%b;
    a=b;
    b=t;
  }
  return a;
}
int n;
ll a,b;
int main()
{
  scanf("%d",&n);
  for(int i=0;i<n;i++)
  {
    scanf("%d%d",&a,&b);
    printf("%lld\n",a*b/gcd(a>b?a:b,a>b?b:a));
  }
}
