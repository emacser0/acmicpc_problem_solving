// 입력
// 첫째줄에 N, T, P 가 주어진다.
// N: 두번째 줄에 주어지는 점수의 갯수 (0 <= N <= P <= 50)
// T: 태수의 새로운 점수 (0 <= T <= 2,000,000,000)
// P: 랭킹 리스트에 올라갈 수 있는 점수의 개수 (10 <= P <= 50)

// 두번째 줄에 현재 랭킹 리스트에 있는 점수가 비오름차순으로 주어진다.
// 각각의 점수는 T와 마찬가지로 0보다 크거나 같고 2,000,000,000보다 작거나 같다.


#include <cstdio>

void swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;	
}

int main()
{
	int N, T, P;
	scanf("%d %d %d", &N, &T, &P);

	int arr[99];
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", arr + i);

		// Insertion Sort

		for (int j = i; j > 0; --j)
		{
			if (arr[j] >= arr[j - 1])
			{
				swap(arr[j], arr[j - 1]);
			}
		}
	}

	// frontRank: 동점자 중에 가장 앞에 있는 것으로 가정한 등수이다.
	// backRank: 동점자 중에 가장 뒤에 있는 것으로 가정한 등수이다.

	int frontRank = N;
	arr[N] = T;

	while(frontRank > 0)
	{
		if (arr[frontRank] >= arr[frontRank - 1])
		{
			swap(arr[frontRank], arr[frontRank - 1]);
			--frontRank;
		}
		else
		{
			break;
		}
	}	

	int backRank = frontRank;
	while (backRank < N)
	{
		if (arr[backRank] != arr[backRank + 1])
		{
			break;
		}

		++backRank;
	}
	
	printf("%d\n", backRank + 1 <= P ? frontRank + 1 : -1);
}