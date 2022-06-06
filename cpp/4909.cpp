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