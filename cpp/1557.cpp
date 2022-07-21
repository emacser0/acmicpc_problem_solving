#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

int u[999999];

int main()
{
	long long K;
	std::cin >> K;

	long long min = K;
	long long max = 3000000001;

	u[1] = 1;
	for (long long i = 1; i * i <= max; ++i)
	{
		for (long long j = 2 * i; j * j <= max; j += i)
		{
			u[j] -= u[i];
		}
	}

	
	while (min < max)
	{
		long long mid = (max + min) / 2;

		long long cnt = 0;
		for (int i = 1; i * i <= mid; ++i)
		{
			cnt += u[i] * (mid / (i * i));
		}

		if (cnt >= K)
		{
			max = mid;
		}
		else if (cnt < K)
		{
			min = mid + 1;
		}
	}

	std::cout << min << std::endl;
}