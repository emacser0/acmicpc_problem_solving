// �Է�
// ù°�ٿ� ���� N (0 �� N �� 1,000,000,000,000,000,000) �� �־�����.

// ���
// �Է����� �־��� ���� ���� �ٸ� M���� ���丮���� ������ ��Ÿ�� �� ������ "YES", ��Ÿ�� �� ������ "NO"�� ����Ѵ�.

#include <cstdio>

using ull = unsigned long long;

// factorials: �̸� ���� ���丮��, factorial(20) > 1,000,000,000,000,000,000 �̹Ƿ� factorial(19)������ �����.

ull factorials[20] = {1, 1, };

// target: M���� ���丮���� ������ ��Ÿ���� �ϴ� ��
// sum: ���� ���丮�� ������ ��
// index: ���� ��Ʈ��ŷ �ε�����

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