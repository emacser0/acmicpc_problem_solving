#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);

	while (T--)
	{
		int A, B;
		scanf("%d %d", &A, &B);

		int s = 0;
		while (A--)
		{
			int C, D, E;
			scanf("%d %d %d", &C, &D, &E);

			s += (B / (float)C) * E <= D;
		}

		printf("%d\n", s);
	}
}