#include <iostream>

bool checkLabel(int v, int l)
{
	while (v)
	{
		if (v % 10 == l)
		{
			return false;
		}

		v /= 10;
	}

	return true;
}

int main()
{
	int n, l;
	scanf("%d%d", &n, &l);

	int v = 1;
	int cnt = 0;

	while (cnt < n)
	{
		if (checkLabel(v, l))
		{
			cnt += 1;
		}

		v += 1;
	}

	printf("%d\n", v - 1);
}