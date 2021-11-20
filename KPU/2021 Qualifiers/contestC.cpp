#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <functional>
#include <set>
#include <cstdio>

long long L[1000004];

int mainC()
{
	long long N, M;

	std::cin >> N >> M;

	long long max = 0;

	for (int i = 0; i < N; ++i)
	{
		long long t;
		std::cin >> t;
		L[i] = t;

		max = max < t ? t : max;
	}

	long long bottom = 0;
	long long top = max;
	long long mid = (top + bottom) / 2;

	long long max_h = 0;

	while (bottom <= top)
	{
		mid = (top + bottom) / 2;

		long long sum = 0;
		for (int i = 0; i < N; ++i)
		{
			if (L[i] > mid)
			{
				sum += L[i] - mid;
			}
		}

		if (sum > M)
		{
			bottom = mid + 1;
			max_h = max_h < mid ? mid : max_h;
		}
		else if (sum < M)
		{
			top = mid - 1;
		}
		else
		{
			max_h = max_h < mid ? mid : max_h;
			break;
		}
	}

	std::cout << max_h << std::endl;

	return 0;
}