#include <iostream>

int r[1000004];

int main()
{
	int A, B, N;
	scanf("%d %d %d", &A, &B, &N);

	int a = A;
	int ri = 0;
	while (N-- >= 0)
	{
		while (a >= B)
		{
			a -= B;
			++r[ri];
		}

		a *= 10;
		++ri;
	}
	printf("%d\n", r[ri - 1]);
}