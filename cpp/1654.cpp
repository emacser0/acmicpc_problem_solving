#include <iostream>

int lines[10001];

int main()
{
	int K, N;
	std::cin >> K >> N;

	long long min = 1;
	long long max = 0;
	for (int i = 0; i < K; ++i)
	{
		std::cin >> lines[i];

		max = max > lines[i] ? max : lines[i];
	}

	long long maxLength = 0;
	while (min <= max)
	{
		long long mid = (min + max) / 2;

		int cnt = 0;
		for (int i = 0; i < K; ++i)
		{
			if (lines[i] < mid)
			{
				continue;
			}

			cnt += lines[i] / mid;
		}

		if (cnt >= N)
		{
			min = mid + 1;

			maxLength = maxLength > mid ? maxLength : mid;
		}
		else
		{
			max = mid - 1;
		}
	}

	std::cout << maxLength << std::endl;
}