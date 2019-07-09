#include <iostream>
#include <algorithm>
using namespace std;
int Answer;
int dp[1000001];
int main(int argc, char** argv)
{
	int T, test_case;
  cin >> T;
  for(int i = 0; i <= 100000; ++i)
  {
    for(int j = i, d = 1; j + d <= 100000; ++d)
    {
      j += d;
      if(dp[j] != 0)
      {
        dp[j] = min(dp[j], dp[i] + d);
      }
      else
      {
        dp[j] = dp[i] + d;
      }
    }
  }

	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 0;
    int x, y, max = 0;
    cin >> x >> y;
    for(int i = x; i <= y; ++i)
    {
      max = max > dp[i]? max : dp[i];
    }
    Answer = max;
    cout << "Case #" << test_case + 1 << "\n" << Answer << "\n";
	}
	return 0;
}
