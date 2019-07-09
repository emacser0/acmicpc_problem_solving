#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
long long Answer;
long long sum(long long n)
{
  return n * (n + 1) / 2;
}
long long first_search(long long n, long long *cnt)
{
  long long d = floor(sqrtl(2 * n));
  long long i = sum(d);
  *cnt = d;
  return i;
}
long long go(long long a, long long b)
{
  long long i = a, d = 0;
  for(; i + d + 1 <= b;)
  {
    d += 1;
    i += d;
  }
  if(i < b)
  {
    d += go(i, b);
  }
  return d;
}
long long calculate(long long x, long long y)
{
    long long max = 0;
    long long last_cnt;
    long long last = first_search(y, &last_cnt);
    long long first_cnt = last_cnt - 1;
    long long first = last - last_cnt;
    long long start = x < first ? first : x,
              end = last <= y ? last : y;
    for(long long i = start; i < end; ++i)
    {
      long long result = first_cnt + go(first, i);
      // printf("result[%d] = %d\n", i, result);
      max = max > result? max : result;
    }
    start = x < last ? last : x;
    for(long long i = start; i <= y; ++i)
    {
      long long result = last_cnt + go(last, i);
      // printf("result[%d] = %d\n", i, result);
      max = max > result ? max : result;
    }
    return max;
}
int main(int argc, char** argv)
{
	int T, test_case;
  cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 0;
    long long x, y;
    cin >> x >> y;
    Answer = calculate(x, y);
    cout << "Case #" << test_case + 1 << "\n" << Answer << "\n";
	}
	return 0;
}
