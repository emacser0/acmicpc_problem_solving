#include <cstdio>
#include <cstring>

int table[26] = {
	4, 5, 6,
	8, 9, 10,
	16, 17, 18,
	32, 33, 34,
	64, 65, 66,
	128, 129, 130, 131,
	256, 257, 258,
	512, 513, 514, 515
};

int main()
{
	int p, w;
	char s[1004];

	scanf("%d %d\n", &p, &w);
	fgets(s, 1001, stdin);

	int prevIndex = -1;
	int t = 0;

	for (int i = 0; i < strlen(s) - 1; ++i)
	{
		if (s[i] == ' ')
		{
			t += p;
			prevIndex = -1;
			continue;
		}

		int offset = table[s[i] - 'A'] % 4 + 1;
		int index = table[s[i] - 'A'] - offset;

		t += w * (prevIndex == index) + offset * p;

		prevIndex = index;
	}

	printf("%d\n", t);
}