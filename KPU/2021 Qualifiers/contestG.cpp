#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <array>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <functional>
#include <set>
#include <cstdio>

char map[2004][2004];
long long dp[2004][2004];

struct Point
{
	Point(int x, int y, long long cnt, int direction = 0)
	{
		this->x = x;
		this->y = y;
		this->cnt = cnt;
		this->direction = direction;
	}

	int x;
	int y;
	long long cnt;
	int direction = 0;
};

int main()
{
	int M;
	int N;
	std::cin >> M >> N;

	int x = 0;
	int y = 0;

	std::vector<Point> endPoints;

	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			std::cin >> map[i][j];

			if (map[i][j] == 'G')
			{
				x = j;
				y = i;
			}
			else if (map[i][j] == 'S')
			{
				endPoints.push_back(Point(j, i, 0));
			}
		}
	}

	std::deque<Point> queue;

	queue.push_back(Point(x - 1, y, 1, 0));
	queue.push_back(Point(x + 1, y, 1, 1));
	queue.push_back(Point(x, y - 1, 1, 2));
	queue.push_back(Point(x, y + 1, 1, 3));

	dp[y][x] = 1;

	while (!queue.empty())
	{
		Point top = queue[0];
		int x = top.x;
		int y = top.y;
		int cnt = top.cnt;
		int direction = top.direction;

		queue.pop_front();

		if (x < 0 || y < 0 || x >= N || y >= M)
		{
			continue;
		}

		if (dp[y][x] == 0 || dp[y][x] > cnt)
		{
			dp[y][x] = cnt;
		}
		else
		{
			continue;
		}

		if (map[y][x] == 'S')
		{
			continue;
		}
		else if (map[y][x] == 'L')
		{
			if (direction == 0)
			{
				queue.push_back(Point(x, y - 1, cnt + 1, 2));
			}
			if (direction == 1)
			{
				queue.push_back(Point(x, y + 1, cnt + 1, 3));
			}
			if (direction == 2)
			{
				queue.push_back(Point(x + 1, y, cnt + 1, 1));
			}
			if (direction == 3)
			{
				queue.push_back(Point(x - 1, y, cnt + 1, 0));
			}

		}
		else if (map[y][x] == 'R')
		{
			if (direction == 0)
			{
				queue.push_back(Point(x, y + 1, cnt + 1, 3));
			}
			if (direction == 1)
			{
				queue.push_back(Point(x, y - 1, cnt + 1, 2));
			}
			if (direction == 2)
			{
				queue.push_back(Point(x + 1, y, cnt + 1, 1));
			}
			if (direction == 3)
			{
				queue.push_back(Point(x - 1, y, cnt + 1, 0));
			}
		}
		else if (map[y][x] == '.')
		{
			queue.push_back(Point(x - 1, y, cnt + 1, 0));
			queue.push_back(Point(x + 1, y, cnt + 1, 1));
			queue.push_back(Point(x, y - 1, cnt + 1, 2));
			queue.push_back(Point(x, y + 1, cnt + 1, 3));
		}
	}

	int min = 9999999;

	/*

	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			std::cout << dp[i][j] << " ";
		}

		std::cout << std::endl;
	}

	*/

	for (auto endPoint : endPoints)
	{
		int v = dp[endPoint.y][endPoint.x];

		if (v == 0)
		{
			continue;
		}

		min = min > v ? v : min;
	}

	std::cout << min << std::endl;
}