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

int cache[999];

int mainA()
{
	int n;
	std::cin >> n;

	std::string str;
	std::cin >> str;

	int max = 0;
	int min = 0;

	int current = 0;

	for (int i = 0; i < str.size(); ++i)
	{
		char ch = str[i];
		if(ch == '+')
		{
			++current;
		}
		else if(ch == '-')
		{
			--current;
		}
		cache[i] = current;

		max = max < current ? current : max;
		min = min > current ? current : min;
	}

	char map[120][120];

	int width = n;
	int height = max - min;

	int index = height + min;

	for (int i = 0; i < 110; ++i)
	{
		for (int j = 0; j < 110; ++j)
		{
			map[i][j] = '.';
		}
	}

	if (max == 0)
	{
		index = 0;
	}
	else if (min == 0)
	{
		index = height - 1;
	}
	else
	{
		if (str[0] == '+')
		{
			index = height + min - 1;
		}
		else
		{
			index = height + min;
		}
	}

	int real_height = height;

	for (int i = 0; i < n; ++i)
	{
		if (str[i] == '+')
		{
			map[index][i] = '/';
		}
		else if (str[i] == '=')
		{
			map[index][i] = '_';
		}
		else if (str[i] == '-')
		{
			map[index][i] = '\\';
		}

		if (i == n - 1)
		{
			break;
		}

		if (str[i] == '+' && str[i + 1] != '-')
		{
			index--;
		}
		else if (str[i] == '-' && str[i + 1] == '-')
		{
			index++;
		}
		else if (str[i] == '=' && str[i + 1] == '-')
		{
			index++;
		}

		real_height = real_height < index + 1 ? index + 1 : real_height;
	}

	for (int i = 0; i < real_height; ++i)
	{
		std::string s;
		bool flag = false;
		for (int j = 0; j < width; ++j)
		{
			s += map[i][j];
			if (map[i][j] != '.')
			{
				flag = true;
			}
		}
		if (flag)
		{
			std::cout << s << std::endl;
		}		
	}

	if (max == min)
	{
		for (int i = 0; i < n; ++i)
		{
			std::cout << '_';
		}

		std::cout << std::endl;
	}

	return 0;
}