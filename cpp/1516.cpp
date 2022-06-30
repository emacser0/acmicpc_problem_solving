#include <iostream>
#include <vector>
#include <deque>

std::vector<int> graph[504];

int times[504];
int maxElapsed[504];
int parentCount[504];

int max(int a, int b)
{
	return a > b ? a : b;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	int N;
	std::cin >> N;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> times[i];

		while (true)
		{
			int t = 0;

			std::cin >> t;
			if (t == -1)
			{
				break;
			}
			
			graph[t - 1].push_back(i);
			++parentCount[i];
		}
	}

	std::deque<int> q;

	for (int i = 0; i < N; ++i)
	{
		if (parentCount[i] == 0)
		{
			maxElapsed[i] = times[i];
			q.push_front(i);
		}
	}

	while (q.size())
	{
		int current = q.back();
		q.pop_back();

		for (auto next : graph[current])
		{
			maxElapsed[next] = max(maxElapsed[next], maxElapsed[current] + times[next]);
			--parentCount[next];

			if (parentCount[next] == 0)
			{
				q.push_front(next);
			}
		}
	}

	for (int i = 0; i < N; ++i)
	{
		std::cout << maxElapsed[i] << std::endl;
	}
}