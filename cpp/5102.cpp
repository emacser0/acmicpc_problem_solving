#include <cstdio>

int main()
{
	while (true)
	{
		int A, B;
		scanf("%d %d", &A, &B);

		if ((A | B) == 0)
		{
			break;
		}

		A -= B;
		int cnt = A % 2 && A >= 3;
		while (A % 2 && A >= 3)
		{
			A -= 3;
		}

		printf("%d %d\n", A / 2, cnt);
	}
}