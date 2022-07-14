#include <iostream>

int main()
{
	int K;
	int N;
	scanf("%d", &K);
	scanf("%d", &N);

	int t = 0;

	while (N--)
	{
		int T;
		char Z;
		scanf("%d %c\n", &T, &Z);

		t += T;

		if (t >= 210)
		{
			break;
		}

		if (Z == 'T')
		{
			K = K % 8 + 1;
		}
	}
	
	printf("%d\n", K);
}