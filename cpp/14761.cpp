#include <cstdio>

int main()
{
	int N, X, Y;
	scanf("%d %d %d", &X, &Y, &N);
	for (int i = 1; i <= N; ++i)
	{
		if (i % X == 0 || i % Y == 0)
		{
			printf("%s%s\n", i % X ? "" : "Fizz", i % Y ? "" : "Buzz");
		}
		else
		{
			printf("%d\n", i);
		}
	}
}