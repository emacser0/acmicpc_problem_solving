#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int Answer;
int dp[1000000], max;
int main(int argc, char** argv)
{
	int T, test_case;
  scanf("%d",&T);
	dp[2] = 1;
  for(int i = 3; i <= 1000000; ++i)
  {
		if(i%2)
		{
			dp[i] = dp[(i+1)/2] + 2;
		}
		else
		{
			dp[i] = dp[i/2] + 1;
		}
  }
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 0;
    int a, b;
    scanf("%d%d",&a, &b);
    for(int i=a;i<=b;++i)
    {
			Answer += dp[i];
    }
    printf("Case #%d\n",test_case+1);
    printf("%d\n",Answer);
	}
	return 0;
}
