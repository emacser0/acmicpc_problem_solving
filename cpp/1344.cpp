#include <iostream>
double a_p,b_p;
int primes[7]={2,3,5,7,11,13,17};
double dp[19][19][19];
int
isprime(int x)
{
  for(int i=0;i<7;i++)
  {
    if(x==primes[i])
    {
      return 1;
    }
  }
  return 0;
}
int main()
{
  std::cin >> a_p >> b_p;
  a_p/=100.0;
  b_p/=100.0;
  dp[0][0][0]=(1-a_p)*(1-b_p);
  dp[0][1][0]=a_p*(1-b_p);
  dp[0][0][1]=(1-a_p)*b_p;
  dp[0][1][1]=a_p*b_p;
  for(int i=1;i<18;i++)
  {
    for(int j=0;j<=i+1;j++)
    {
      for(int k=0;k<=i+1;k++)
      {
        if(j>0)
        {
          dp[i][j][k]+=a_p*(1-b_p)*dp[i-1][j-1][k];
        }
        if(k>0)
        {
          dp[i][j][k]+=(1-a_p)*b_p*dp[i-1][j][k-1];
        }
        if(j>0&&k>0)
        {
          dp[i][j][k]+=a_p*b_p*dp[i-1][j-1][k-1];
        }
        dp[i][j][k]+=(1-a_p)*(1-b_p)*dp[i-1][j][k];
      }
    }
  }
  double sum=0.0;
  for(int i=0;i<19;i++)
  {
    for(int j=0;j<19;j++)
    {
      if(isprime(i)==1||isprime(j)==1)
      {
        sum += dp[17][i][j];
      }
    }
  }
  std::cout.precision(10);
  std::cout << sum <<"\n";
}
