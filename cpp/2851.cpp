#include <cstdio>

int main()
{
	int s = 0;

	for (int i = 0; i < 10; ++i)
	{
		int x;
		scanf("%d", &x);

		if (s + x > 100 && 100 - s < s + x - 100)
		{
			break;
		}

		s += x;
	}

	printf("%d\n", s);
}