#include <iostream>
#include <set>

char flag[6][10];
std::set<char> s;

int main()
{
	for (int i = 0; i < 6; ++i)
	{
		std::cin >> flag[i];
		for (int j = 0; j < 9; ++j)
		{
			s.insert(flag[i][j]);
		}
	}

	s.insert('x');

	int minCnt = 54;

	char t[3];

	for (auto a : s)
	{
		for (auto b : s)
		{
			for (auto c : s)
			{
				if (a == b || b == c)
				{
					continue;
				}
				char t[3] = { a, b, c };

				int cntA = 0;
				int cntB = 0;
				for (int i = 0; i < 3; ++i)
				{
					for (int j = i * 2; j < (i + 1) * 2; ++j)
					{
						for (int k = 0; k < 9; ++k)
						{
							cntA += flag[j][k] != t[i];
						}
					}

					for (int j = i * 3; j < (i + 1) * 3; ++j)
					{
						for (int k = 0; k < 6; ++k)
						{
							cntB += t[i] != flag[k][j];
						}
					}
				}

				minCnt = minCnt < cntA ? minCnt : cntA;
				minCnt = minCnt < cntB ? minCnt : cntB;
			}
		}
	}

	std::cout << minCnt << std::endl;
}