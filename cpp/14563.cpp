#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i)
	{
		int N;
		scanf("%d", &N);

		int s = 0;
		for (int i = 1; i <= N / 2; ++i)
		{
			if (N % i == 0)
			{
				s += i;
			}
		}

		if (s == N)
		{
			printf("Perfect\n");
		}
		else if (s > N)
		{
			printf("Abundant\n");
		}
		else
		{
			printf("Deficient\n");
		}
	}
}