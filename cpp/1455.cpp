#include <iostream>

bool coins[101][101];

int main()
{
	int N, M;
	std::cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		std::string str;
		std::cin >> str;

		for (int j = 0; j < str.size(); ++j)
		{
			coins[i][j] = str[j] - '0';				
		}
	}

	int cnt = 0;
	for (int i = N - 1; i >= 0; --i)
	{
		for (int j = M - 1; j >= 0; --j)
		{
			if (!coins[i][j])
			{
				continue;
			}

			for (int y = 0; y <= i; ++y)
			{
				for (int x = 0; x <= j; ++x)
				{
					coins[y][x] = !coins[y][x];
				}
			}

			++cnt;
		}
	}

	std::cout << cnt << std::endl;
}