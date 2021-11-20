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

int map[504][504];
int dp[504][504];

int mainE()
{
	int H;
	std::cin >> H;
	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < i + 1; ++j)
		{
			int t;
			std::cin >> map[i][j];
		}
	}

	for (int i = 0; i < H; ++i)
	{
		dp[H - 1][i] = map[H - 1][i];
	}

	for (int i = H - 2; i >= 0; --i)
	{
		for (int j = 0; j < i + 1; ++j)
		{
			int left = dp[i + 1][j];
			int right = dp[i + 1][j + 1];
			dp[i][j] = map[i][j] + (left > right ? left : right);
		}
	}

	std::cout << dp[0][0] << std::endl;

	return 0;
}