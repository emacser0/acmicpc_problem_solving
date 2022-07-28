#include <iostream>
#include <algorithm>

int main()
{
	int N, M;
	std::cin >> N >> M;

	int p[1001];
	int price = 2 << 16;

	for (int i = 0; i < M; ++i)
	{
		std::cin >> p[i];
		price = price < p[i] ? price : p[i];
	}

	std::sort(p, p + M);

	int bestPrice = p[0];
	int maxRevenue = 0;
	for (int i = 0; i < M; ++i)
	{
		int cnt = M - i < N ? M - i : N;
		int revenue = cnt * p[i];

		if (revenue > maxRevenue)
		{
			maxRevenue = revenue;
			bestPrice = p[i];
		}
	}

	std::cout << bestPrice << " " << maxRevenue << std::endl;
}
