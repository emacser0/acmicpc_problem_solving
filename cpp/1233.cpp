#include <cstdio>

int count[81];

int main()
{
	int A, B, C;

	scanf("%d %d %d", &A, &B, &C);

	for (int i = 1; i <= A; ++i)
	{
		for (int j = 1; j <= B; ++j)
		{
			for (int k = 1; k <= C; ++k)
			{
				++count[i + j + k];
			}
		}
	}

	int argmax = 0;
	for (int i = 3; i <= 80; ++i)
	{
		if (count[argmax] < count[i])
		{
			argmax = i;
		}
	}

	printf("%d\n", argmax);
}