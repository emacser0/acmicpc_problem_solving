#include <cstdio>
#include <algorithm>

void swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}

int p[4][2];
int v[3];

bool check()
{
	bool result = true;
	for (int t = 0; t < 4; ++t)
	{
		swap(p[0][0], p[t][0]);
		swap(p[0][1], p[t][1]);

		for (int i = 0; i < 3; ++i)
		{
			int dx = p[0][0] - p[i + 1][0];
			int dy = p[0][1] - p[i + 1][1];
			v[i] = dx * dx + dy * dy;
		}

		std::sort(v, v + 3);
		
		result &= (v[0] == v[1] && v[1] * 2 == v[2]);
	}

	return result;
}

int main()
{
	int T;

	scanf("%d", &T);

	while (T--)
	{
		for (int i = 0; i < 4; ++i)
		{
			scanf("%d %d", &p[i][0], &p[i][1]);
		}

		printf("%d\n", check());
	}
}