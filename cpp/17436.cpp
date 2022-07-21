#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <algorithm>

int main()
{
	long long N, M;
	std::cin >> N >> M;

	long long primes[10];
	for (int i = 0; i < N; ++i)
	{
		std::cin >> primes[i];
	}

	long long cnt = 0;
	bool p[10];
	for (int i = 0; i < N; ++i)
	{		
		std::fill(p, p + N, 0);

		for (int j = N - i - 1; j < N; ++j)
		{
			p[j] = 1;			
		}

		do
		{
			long long m = 1;
			for (int j = 0; j < N; ++j)
			{
				if (p[j])
				{
					m *= primes[j];
				}
			}

			if ((i + 1) % 2)
			{
				cnt += M / m;
			}
			else
			{
				cnt -= M / m;
			}
		} while (std::next_permutation(p, p + N));
	}

	std::cout << cnt << std::endl;
}