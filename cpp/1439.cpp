// 입력
// 한 줄에 길이가 100만보다 작은 문자열이 주어진다.

// 출력
// 모두 같은 숫자로 만들기 위해 필요한 최소 뒤집기 횟수를 출력.

#include <cstdio>
#include <cstring>

int main()
{
	// buf: 입력받은 문자열을 담는 버퍼

	char buf[1000004];
	scanf("%s", buf);

	int len = strlen(buf);

	// streaks: streaks[0]는 연속된 0이 몇개나 있는지, streaks[1]은 연속된 1이 몇개나 있는지를 의미한다.
	// currentStreakBit: 현재 연속되고 있는 bit가 0인지, 1인지를 나타낸다. -1로 시작한다.

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