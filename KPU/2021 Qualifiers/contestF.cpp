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

int map[4][4];

int mainF()
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			std::cin >> map[i][j];
		}
	}

	char ch;
	std::cin >> ch;

	if (ch == 'L')
	{
		for (int i = 0; i < 4; ++i)
		{
			std::vector<int> r;

			for (int j = 0; j < 4; ++j)
			{
				if (map[i][j] == 0)
				{
					continue;
				}

				int next_j = j + 1;
				
				while (next_j < 4 && map[i][next_j] == 0)
				{
					++next_j;
				}

				if (next_j < 4 && map[i][j] == map[i][next_j])
				{
					r.push_back(map[i][j] + map[i][next_j]);
					j = next_j;
				}
				else
				{
					r.push_back(map[i][j]);
				}
			}

			while (r.size() < 4)
			{
				r.push_back(0);
			}

			for (int j = 0; j < 4; ++j)
			{
				map[i][j] = r[j];
			}
		}
	}
	else if (ch == 'R')
	{
		for (int i = 0; i < 4; ++i)
		{
			std::vector<int> r;

			for (int j = 3; j >= 0; --j)
			{
				if (map[i][j] == 0)
				{
					continue;
				}

				int next_j = j - 1;

				while (next_j >= 0 && map[i][next_j] == 0)
				{
					--next_j;
				}

				if (next_j >= 0 && map[i][j] == map[i][next_j])
				{
					r.push_back(map[i][j] + map[i][next_j]);
					j = next_j;
				}
				else
				{
					r.push_back(map[i][j]);
				}
			}

			while (r.size() < 4)
			{
				r.push_back(0);
			}

			for (int j = 0; j < 4; ++j)
			{
				map[i][j] = r[3 - j];
			}
		}
	}
	else if (ch == 'U')
	{
		for (int i = 0; i < 4; ++i)
		{
			std::vector<int> r;

			for (int j = 0; j < 4; ++j)
			{
				if (map[j][i] == 0)
				{
					continue;
				}

				int next_j = j + 1;

				while (next_j < 4 && map[next_j][i] == 0)
				{
					++next_j;
				}

				if (next_j < 4 && map[j][i] == map[next_j][i])
				{
					r.push_back(map[j][i] + map[next_j][i]);
					j = next_j;
				}
				else
				{
					r.push_back(map[j][i]);
				}
			}

			while (r.size() < 4)
			{
				r.push_back(0);
			}

			for (int j = 0; j < 4; ++j)
			{
				map[j][i] = r[j];
			}
		}
	}
	else if (ch == 'D')
	{
		for (int i = 0; i < 4; ++i)
		{
			std::vector<int> r;

			for (int j = 3; j >= 0; --j)
			{
				if (map[j][i] == 0)
				{
					continue;
				}

				int next_j = j - 1;

				while (next_j >= 0 && map[next_j][i] == 0)
				{
					--next_j;
				}

				if (next_j >= 0 && map[j][i] == map[next_j][i])
				{
					r.push_back(map[j][i] + map[next_j][i]);
					j = next_j;
				}
				else
				{
					r.push_back(map[j][i]);
				}
			}

			while (r.size() < 4)
			{
				r.push_back(0);
			}

			for (int j = 0; j < 4; ++j)
			{
				map[j][i] = r[3 - j];
			}
		}
	}

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			std::cout << map[i][j];
			if (j < 3)
			{
				std::cout << " ";
			}
		}

		std::cout << std::endl;
	}

	return 0;
}