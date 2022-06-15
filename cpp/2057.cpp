// 입력
// 첫째줄에 정수 N (0 ≤ N ≤ 1,000,000,000,000,000,000) 이 주어진다.

// 출력
// 입력으로 주어진 수를 서로 다른 M개의 팩토리얼의 합으로 나타낼 수 있으면 "YES", 나타낼 수 없으면 "NO"를 출력한다.

#include <cstdio>

using ull = unsigned long long;

// factorials: 미리 계산된 팩토리얼, factorial(20) > 1,000,000,000,000,000,000 이므로 factorial(19)까지만 계산함.

ull factorials[20] = {1, 1, };

// target: M개의 팩토리얼의 합으로 나타내야 하는 값
// sum: 현재 팩토리얼 값들의 합
// index: 현재 백트래킹 인덱스값

bool findSum(ull target, ull sum, int index)
{
	if (target == 0)
	{
		return false;
	}

	if (sum >= target)
	{
		return sum == target;
	}	

	if (index < 0)
	{
		return false;
	}

	return findSum(target, sum, index - 1) || findSum(target, sum + factorials[index], index - 1);
}

int main()
{
	ull N;
	scanf("%lld", &N);

	for (int i = 2; i < 20; ++i)
	{
		factorials[i] = factorials[i - 1] * i;
	}

	printf("%s\n", findSum(N, 0, 19) ? "YES" : "NO");
}