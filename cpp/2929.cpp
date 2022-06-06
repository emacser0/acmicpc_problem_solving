#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctype.h>

char s[204];
int a, c;

int main()
{
	scanf("%s", s);

	for (int i = 0; i < strlen(s); ++i)
	{
		++a;
		if (isupper(s[i + 1]) && a % 4)
		{
			c += 4 - a % 4;
			a += 4 - a % 4;
		}
	}

	printf("%d\n", c);
}