#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int Answer, a, b, is_prime[30004];
int remove(int x, int digit_index)
{
  int p = powl(10, digit_index);
  return x / (p * 10) * p + (x - (x / p * p));
}

int get_digit_count(int x)
{
  int cnt = 0;
  while(x)
  {
    x /= 10;
    cnt += 1;
  }
  return cnt;
}

int count_prime(int x)
{
  if(is_prime[x] == 0)
  {
    return 0;
  }
  int max = 0, l = get_digit_count(x);
  if(l < 2) return 1;
  for(int i = 0; i < l; ++i)
  {
    int r = count_prime(remove(x, i));
    max = r > max ? r : max;
  }
  return max + 1;
}

int main(int argc, char** argv)
{
	int T, test_case;
	std::cin >> T;
  std::fill(is_prime + 2, is_prime + 30004, 1);
	for (int i = 2; i * i <= 30000; ++i)
	{
		if (is_prime[i])
    {
      for (int j = i * 2; j <= 30000; j += i)
      {
			    is_prime[j] = 0;
      }
    }
	}
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 0;
    cin >> a >> b;
    int ra = count_prime(a), rb = count_prime(b);
    cout << "Case #" << test_case+1 << endl;
    if(ra > rb)
    {
      cout << 1 << endl;
    }
    else if(ra < rb)
    {
      cout << 2 << endl;
    }
    else
    {
      cout << 3 << endl;
    }
	}
	return 0;
}
