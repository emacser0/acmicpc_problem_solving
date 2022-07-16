#include <iostream>

long long n[200001];

int main()
{
	int T;
	std::cin >> T;	

	while (T--)
	{
		int N, M;
		std::cin >> N >> M;
		
		long long ns = 0;
		long long ms = 0;

		for (int i = 0; i < N; ++i)
		{
			std::cin >> n[i];
			ns += n[i];
		}
		
		for (int i = 0; i < M; ++i)
		{
			long long t;
			std::cin >> t;

			ms += t;
		}

		double na = ns / (double)N;
		double ma = ms / (double)M;

		int cnt = 0;
		for (int i = 0; i < N; ++i)
		{
			if ((ns - n[i]) / (double)(N - 1) > na &&
				(ms + n[i]) / (double)(M + 1) > ma)
			{
				++cnt;
			}
		}

		std::cout << cnt << std::endl;
	}
}