#include <iostream>

int N, M, K;

bool map[200][200][2];
unsigned long long dp[200][200];

int main()
{
	std::cin >> N >> M;
	std::cin >> K;

	dp[0][0] = 1;

	for (int i = 0; i < K; i++) {
		int A, B, C, D;
		std::cin >> A >> B >> C >> D;

		map[B + D][A + C][0] = B != D;
		map[B + D][A + C][1] = A != C;
	}

	for (int i = 0; i <= M; i++) {
		for (int j = 0; j <= N; j++) {
			dp[i + 1][j] += dp[i][j] * !map[2 * i + 1][2 * j][0];
			dp[i][j + 1] += dp[i][j] * !map[2 * i][2 * j + 1][1];
		}
	}

	std::cout << dp[M][N] << std::endl;
}