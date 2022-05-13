#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);

	while (T--)
	{
		int N;
		scanf("%d", &N);

		int s = 0;
		for (int i = 2; i <= N ; ++i)
		{
			int n = N;
			for(int n = N; n % i == 0; n /= i)
			{
				s += n % i == 0;
			}
		}

		printf("%d\n", s);
	}
}