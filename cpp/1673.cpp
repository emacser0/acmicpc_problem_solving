// �Է�
// �� �ٸ��� N�� K�� �־���. ( 1 < k <= n <= 1,000,000,000 )

#include <cstdio>

int main()
{
	int N, K;

	// cnt: �� ���� ġŲ ��
	// stamp: ���±��� ���� ���� ��

	while (~scanf("%d %d", &N, &K))
	{
		int cnt = 0;
		int stamp = 0;
		while (N > 0 || stamp >= K)
		{			
			cnt += N;
			stamp += N;
			N = 0;			

			while (stamp >= K)
			{
				++N;
				stamp -= K;
			}
		}

		printf("%d\n", cnt);
	}
}