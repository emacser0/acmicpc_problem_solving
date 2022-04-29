#include <cstdio>

char dnaTable[4][5] = { "ACAG", "CGTA", "ATCG", "GAGT" };
int indexTable[99];

char S[1000004];

int main()
{
	int N = 0;

	indexTable['A'] = 0;
	indexTable['G'] = 1;
	indexTable['C'] = 2;
	indexTable['T'] = 3;		

	scanf("%d%s", &N, S);

	while (N--)
	{
		S[N - 2] = dnaTable[indexTable[S[N - 2]]][indexTable[S[N - 1]]];
	}

	printf("%c\n", S[0]);
}