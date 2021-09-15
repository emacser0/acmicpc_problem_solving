#include <iostream>
#include <vector>
#include <cstring>

std::vector<std::vector<int>> tree;
int cache[1000001][2];
int visited[1000001];

int dfs(int i, int ea)
{
	if (tree[i].size() == 0)
	{
		return ea;
	}

	if (cache[i][ea] > -1)
	{
		return cache[i][ea];
	}

	visited[i] = 1;

	cache[i][ea] = ea;
	if (ea)
	{
		for (int j = 0; j < tree[i].size(); ++j)
		{
			if (!visited[tree[i][j]])
			{
				int a = dfs(tree[i][j], 0);
				int b = dfs(tree[i][j], 1);
				cache[i][ea] += a < b ? a : b;
			}
		}
	}
	else
	{
		for (int j = 0; j < tree[i].size(); ++j)
		{
			if (!visited[tree[i][j]])
			{
				cache[i][ea] += dfs(tree[i][j], 1);
			}
		}
	}

	visited[i] = 0;

	return cache[i][ea];
}

int main()
{
	int n;
	std::cin >> n;

	for (int i = 0; i < n; ++i)
	{
		tree.push_back(std::vector<int>());
	}

	memset(cache, -1, sizeof(cache));
	
	for (int i = 0; i < n - 1; ++i)
	{
		int u, v;

		std::cin >> u >> v;
		tree[u - 1].push_back(v - 1);
		tree[v - 1].push_back(u - 1);
	}

	int a = dfs(0, 0);
	int b = dfs(0, 1);

	std::cout << (a < b ? a : b) << std::endl;
}