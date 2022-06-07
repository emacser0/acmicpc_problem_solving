// 입력
// 매 줄마다 0 이상 10 이하의 정수 6개가 주어짐.
// "0 0 0 0 0 0" 은 입력의 끝을 의미함.

// 출력
// 각 줄마다 최고점과 최저점을 제외한 4개 항목의 점수의 평균을 구해야 함.
// 소숫점 맨 끝 0을 제외한 실수를 출력해야함.

#include <cstdio>

int main()
{
	while (true)
	{
		int scoreSum = 0;
		int scoreMax = 0;
		int scoreMin = 10;
		for (int i = 0; i < 6; ++i)
		{
			int score = 0;
			scanf("%d", &score);

			scoreSum += score;
			scoreMax = score > scoreMax ? score : scoreMax;
			scoreMin = score < scoreMin ? score : scoreMin;
		}

		if (scoreSum == 0)
		{
			break;
		}

		printf("%.3g\n", (scoreSum - scoreMax - scoreMin) / 4.0f);
	}
}