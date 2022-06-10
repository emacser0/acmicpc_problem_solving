// 입력
// 매 줄마다 N과 K가 주어짐. ( 1 < k <= n <= 1,000,000,000 )

#include <cstdio>

int main()
{
	int N, K;

	// cnt: 총 먹은 치킨 수
	// stamp: 여태까지 모은 도장 수

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