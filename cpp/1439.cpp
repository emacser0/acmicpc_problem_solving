// �Է�
// �� �ٿ� ���̰� 100������ ���� ���ڿ��� �־�����.

// ���
// ��� ���� ���ڷ� ����� ���� �ʿ��� �ּ� ������ Ƚ���� ���.

#include <cstdio>
#include <cstring>

int main()
{
	// buf: �Է¹��� ���ڿ��� ��� ����

	char buf[1000004];
	scanf("%s", buf);

	int len = strlen(buf);

	// streaks: streaks[0]�� ���ӵ� 0�� ��� �ִ���, streaks[1]�� ���ӵ� 1�� ��� �ִ����� �ǹ��Ѵ�.
	// currentStreakBit: ���� ���ӵǰ� �ִ� bit�� 0����, 1������ ��Ÿ����. -1�� �����Ѵ�.

	int streaks[2] = { 0, 0 };
	int currentStreakBit = -1;
	for (int i = 0; i < len; ++i)
	{
		bool bit = buf[i] - '0';
		if (bit != currentStreakBit)
		{
			++streaks[bit];

			currentStreakBit = bit;
		}
	}

	printf("%d\n", streaks[0] < streaks[1] ? streaks[0] : streaks[1]);
}