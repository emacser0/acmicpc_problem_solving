#include <cstdio>

int cnt[51];

int main()
{
	int N, M, L;
	scanf("%d %d %d", &N, &M, &L);

	cnt[0] = 1;

	int total = 0;
	for (int current = 0; cnt[current] < M; ++total)
	{
		current = (current + (cnt[current] % 2 ? L : -L)) % N;
		if (current < 0)
		{
			current += N;
		}

		++cnt[current];
	}

	printf("%d\n", total);
}