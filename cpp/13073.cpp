// 입력
// 첫줄에는 테스트 케이스의 개수인 T (1<= T <= 10000)
// 두번째 줄부터 T개의 줄에 1<= N <= 10000인 양의 정수 N이 주어진다.

// 출력
// T개의 N에 대해
// S1 S2 S3
// 의 형태로 출력하면 된다. S1, S2, S3는 다음과 같다.
// S1: 처음 N개의 양의 정수의 합
// S2: 처음 N개의 홀수인 양의 정수의 합
// S3: 처음 N개의 짝수인 양의 정수의 합

#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; ++i)
	{
		int N;
		scanf("%d", &N);

		printf("%d %d %d\n", N * (N + 1) / 2, N * N, N * (N + 1));
	}
}

/*

// 응용
// S2: N보다 작거나 같은 양의 정수의 합
// S3: N보다 작거타 같은 짝수인 양의 정수의 합

#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; ++i)
	{
		int N;
		scanf("%d", &N);

		printf("%d %d %d\n", N * (N + 1) / 2, (N / 2) * (N / 2), (N / 2) * (N / 2 + 1));
	}
}

*/